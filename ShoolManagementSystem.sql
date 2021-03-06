CREATE TABLE instructor(
    ID CHAR(5),
    name VARCHAR(20) NOT NULL,
    dept_name VARCHAR(20),
    salary NUMERIC(8,2),
    PRIMARY KEY ID,
    FOREIGN KEY(dept_name) REFERENCES department
);

INSERT INTO instructor VALUE(1754060, 'zz','SSE',1000);

DELETE FROM instructor;

DROP TABLE instructor;

ALTER TABLE instructor add school,bonus;

--[基础查询]--
--1.找出所有老师的姓名, 系名, 建筑名--
SELECT name, dept_name, building
FROM instructor, department
WHERE instructor.dept_name = building.dept_name;

SELECT name, dept_name, building
FROM instructor NATURE JOIN building;

--2.找出所有老师的姓名以及所讲述所有课程的ID--
SELECT name, course_id
FROM instructor, teaches
WHERE instructor.ID = teaches.ID;

--3.找出老师的姓名以及他们所讲授课程的名字--
SELECT name, title
FROM instructor, teaches, course
WHERE instructor.ID=teaches.ID and teaches.course_id=course.course_id;

SELECT name, title
FROM instructor NATURE JOIN teaches, course
WHERE teaches.course_id=course.course_id;

--错误方式
SELECT name, title
FROM instructor NATURE JOIN teaches NATURE JOIN course;
--这样选要满足instructor.ID=teaches.ID and instructor.dept_name=course.dept_name
--会遗漏老师开的课程不在本学院的情况

--改造方式
SELECT name, title
FROM (instructor NATURE JOIN teaches) JOIN course USING (course_id);


--[更名运算 -> as]--
--适用于需要比较同一关系中元组的情况, 为此需要把一个关系跟它自身进行笛卡尔积运算

--选择xx>xx, xx<xx的套路
--相同的关系命名为不同的关系 => 做笛卡尔积 => 再选择
--1.查找全部工资比计算机学院某些老师工资高的老师--
SELECT DISTINCT T.name
FROM instructor as T, instructor as S
WHERE T.salary>S.salary and S.dept_name='Comp.Sci';


--[模式匹配 -> like]--
-- %匹配任意子串    _匹配任意一个字符
-- e.g. '_ _ _'匹配只含三个字符的串;  '_ _ _ %'匹配至少含三个字符的串
--1.找出所有建筑命中包含子串'Waston'的所有系名--
SELECT dept_name
FROM department
WHERE building like '%Waston%';

--[排列元组的显示次序 -> order by]--
--1.查找所有教授的信息, 先按工资降序排, 再按名字升序排--
SELECT *
FROM instructor
order by salary desc, name asc;

--[where子句谓词]--
WHERE salary<=100 and salary >=90
WHERE salary between 90 and 100;

WHERE instructor.ID=teaches.ID and dept_name='Biology'
WHERE (instructor.ID, dept_name) = (teaches.ID, 'Biology');

--[集合运算 -> union/intersect/except]--
(SELECT WHERE FROM)
union           --intersect/except
(SELECT WHERE FROM);

--[聚集函数 -> avg/min/max/sum/count]--
--1.求course表中有多少元组--
SELECT count(*)
FROM course;

SELECT count(course_id)     --course_id是主码
FROM course;

--[分组 -> group by]--
--在句句函数之外的属性必须全部出现在group by中
--1.查询每个系的平均工资--
SELECT dept_name, avg(salary) as avg_salary
FROM instructor
group by dept_name;

--错误示例
SELECT dept_name, ID, avg(salary)   --已经按dept_name分组了, 同一组中有好多ID
FROM instructor
group by dept_name;

--2.每个系在2019年春季学期讲授课程的教师人数--
SELECT dept_name, count(ID)
FROM instructor NATURE join teaches
WHERE semester='Spring' and year=2019
group by dept_name;


--[对分组后的元组限定条件 -> having]--
--1.找出平均工资超过42000的所有系--
SELECT dept_name, avg(salary)
FROM instructor
group by dept_name
having avg(salary)>42000;

--2.2019年讲授的每个时间段, 如果该课程有至少2名学生选课, 找出选修它的所有学生的学分平均值--
SELECT course_id, semester, year, sec_id, avg(tot_cred)
FROM student NATURE join takes
WHERE year=2019
group by course_id, semester, year, sec_id
having count(ID)>2;


--[嵌套子查询]--
--[判断属性或元组是否在集合中 -> in/not in]--
--1.找出在2009年秋和2010年春同时开课的课程
SELECT distinct course_id
FROM section
WHERE year=2009 and semester='Fall' and course_id in(
    SELECT course_id
    FROM section
    WHERE year=2010 and semester='Spring'
);

(
    SELECT distinct course_id
    FROM section
    WHERE year=2009 and semester='Fall'
)
intersect
(
    SELECT distinct course_id
    FROM section
    WHERE year=2010 and semester='Spring'
);

--2.找出选修了ID为10111老师讲的课的学生人数
SELECT count(distinct(takes.ID))
FROM takes
WHERE (course_id,sec_id,semester,year) in (
    SELECT course_id,sec_id,semester,year
    FROM teaches
    WHERE teaches.ID=10111;
);

SELECT count(distinct(takes.ID))
FROM takes JOIN teaches USING(course_id,sec_id,semester,year)   --这里不能直接自然连接, takes和teaches都有ID属性, 但是不是一个意思
WHERE teaches.ID=10111;

SELECT count(distinct(takes.ID))
FROM takes, teaches
WHERE (takes.course_id,takes.sec_id,takes.semester,takes.year)=(teaches.course_id,teaches.sec_id,teaches.semester,teaches.year)
    and teaches.ID=10111;

--[集合比较 -> some/all]--
--1.找出教师工资至少比Biology系中某一个老师工资高
SELECT ID, name
FROM instructor
WHERE salary>some(
    SELECT salary
    FROM instructor
    WHERE dept_name='Biology'
);

--2.找出工资比所有Biology系老师都高
--(1)把some改成any
--(2)用聚集函数
WHERE salary>(
    SELECT max(salary)
    FROM instructor
);

--[测试集合的基数,即判断集合是否为空 -> exist]--
--1.找出在2009年秋和2010年春同时开课的课程(前面的例子)
SELECT S.course_id
FROM section as S
WHERE S.year=2009 and S.semester='Fall' and exist(
    SELECT *
    FROM section as T
    WHERE T.year=2010 and T.semester='Spring'
            and S.course_id=T.course_id
);

--B包含在A中 <=> 所有B中的元组都在A中 <=> not exist (B except A)
--2.选修了Biology系开设的所有课程的学生
SELECT S.ID, S.name
FROM student as S
WHERE not exist(
    (
        SELECT course_id
        FROM course
    )
    except
    (
        SELECT course_id
        FROM takes
        WHERE takes.ID=S.ID
    )
);

--[测试一个子查询是否有相同元组 -> unique]--
--1.在2009年最多开设一次的课程
SELECT T.course_id
FROM course as T
WHERE unique (
    SELECT R.course_id
    FROM section as R
    WHERE T.course_id=R.course_id and R.year=2019
);

WHERE 1>=(
    SELECT count(R.course_id)
    ...
);

--2.题干改成至少开设两次
--改为not unique, 其它不变


--[from子句中的子查询]--
--1.找系平均工资超过42000的那些系中教师的平均工资
SELECT dept_name, avg(salary)
FROM instructor
group by dept_name
HAVING avg(salary)>42000;

SELECT dept_name, avg_salary
FROM (
    SELECT dept_name, avg(salary) as avg_salary
    FROM instructor
    GROUP by dept_name
)
WHERE avg_salary>42000;


--2.找所有系中工资总额最大的系
SELECT dept_name, max(total_salary)
FROM (
    SELECT dept_name, sum(salary)
    FROM instructor
    GROUP BY dept_name
) as (dept_name, total_salary);

--?这样是等效的么
SELECT dept_name, sum(salary)
FROM instructor
GROUP BY dept_name
HAVING sum(salary) > (
    SELECT max(salary)
    FROM instructor
    GROUP BY dept_name
);


--[临时关系 -> with]--
--1.找所有工资总额大于所有系平均工资总额的系
WITH dept_total(dept_name, value) AS (
        SELECT dept_name, sum(salary)
        FROM instructor
        GROUP BY dept_name
    ),
    dept_total_avg(value) AS(
        SELECT avg(value)
        FROM dept_total
    )
SELECT dept_name
FROM dept_total, dept_total_avg
WHERE dept_total.value>=dept_total_avg.value;


--[删除]--
--1.删除在Waston大楼的老师
DELETE FROM instructor
WHERE dept_name in (
    SELECT dept_name
    FROM department
    WHERE building='Waston'
);

--2.删除工资低于平均工资的老师
WITH avg_salary(value) as(
    SELECT avg(salary)
    FROM instructor
)
DELETE FROM instructor
WHERE salary<avg_salary.value;
--错误做法, 一边删除一边avg(salary)就变了
DELETE FROM instructor
WHERE salary<(
    SELECT avg(salary)
    FROM instructor
);

--[插入]--
--1.将所有老师的信息查到学生里, 并将tot_cred设为0
INSERT INTO student
    SELECT ID, name, dept_name, 0
    FROM instructor;
--这里不能写 SELECT * => 会导致无线插入

--[更新]--
--1.工资超过10000元的涨工资3%, 其余涨5%
--更新的先后顺序很重要
UPDATE instructor
SET salary=salary*1.03
WHERE salary>10000;
UPDATE instructor
SET salary=salary*1.05
WHERE salary<=10000;

UPDATE instructor
SET salary=
        CASE
            WHEN salary<=10000 then salary*1.05
            ELSE salary*1.03
        END;

--2.把每个学生的tot_cred设置为该学生成功完成(不是F也不是空)的课程学分总和
UPDATE student S
SET tot_cred = (
    SELECT sum(credits)
    FROM takes NATURE JOIN course
    WHERE S.ID=takes.ID and takes.grade is not null and takes.grade<>'F'
);


--[视图 -> view]--
--1.创建系总工资视图
CREATE dept_total_salary(dept_name, total_salary) AS
(
    SELECT dept_name, sum(salary)
    FROM instructor
    GROUP BY dept_name
);

--[函数]--
--1.定义一个函数, 输入一个系名, 输出该系有多少老师
CREATE FUNCTION dept_count(dept_name VARCHAR(20))
RETURNS INTEGER
BEGIN
    DECLARE d_count INTEGER; 
    SELECT count(*) INTO d_count
    FROM instructor
    WHERE instructor.dept_name = dept_name
    return d_count; 
END
--使用该函数找到所有老师数大于12的系名和预算
SELECT dept_name, budget
FROM department
WHERE dept_count(dept_name)>12;
