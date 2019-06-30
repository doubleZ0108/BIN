create TABLE instructor(
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

---[基础查询]---
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
WHERE salary between 90 and 100

WHERE instructor.ID=teaches.ID and dept_name='Biology'
WHERE (instructor.ID, dept_name) = (teaches.ID, 'Biology')

--[集合运算 -> union/intersect/except]--
(SELECT WHERE FROM)
union           --intersect/except
(SELECT WHERE FROM)

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
