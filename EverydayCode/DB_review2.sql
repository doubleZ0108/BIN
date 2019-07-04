--基础查询
select name, dept_name, building
from instructor, department
where instructor.dept_name=department.dept_name;

select name, course_id
from instructor natural join course;

select name, title
from instructor, course, teaches
where instructor.ID=teaches.ID and teaches.course_id=course.course_id;
select name, title
from instructor natural join teaches join course using(course_id);

--查找全部工资比计算机学院某些老师工资高的老师
select distinct T.name, T.salary
from instructor T, instructor S
where T.salary>S.salary and S.dept_name='Comp.Sci.'

select T.name, T.salary
from instructor T
where T.salary>some(
  select salary
  from instructor S
  where S.dept_name='Comp.Sci.'
)

select name, salary
from instructor
where salary > (
  select min(salary)
  from instructor
  where dept_name='Comp.Sci.'
)

--like
select dept_name, building
from department
where building like '%Was%';

--order by
select *
from instructor
order by salary desc, name asc;

--course表有多少元组
select count(*)
from course;
select count(course_id) as count_id
from course;

--group by
select dept_name, avg(salary)
from instructor
group by dept_name;

select dept_name, count(distinct ID)
from teaches natural join instructor
where semester='Spring' and years=2009
group by dept_name;


--平均工资超过42000的所有系
select dept_name, avg(salary)
from instructor
group by dept_name
having avg(salary)>42000;

with dept_avg(dept_name, value) as(
  select dept_name, avg(salary)
  from instructor
  group by dept_name
)
select dept_name, value
from dept_avg
where value>42000;

--2019年讲授的每个时间段, 如果该课程有至少2名学生选课, 找出选修它的所有学生的学分平均值
select course_id,sec_id,semester,year,avg(tot_cred)
from student natural join takes
where year=2009
group by course_id, sec_id, semester, year
having count(ID)>2;

--两个时间段同时开的课
select course_id
from section
where semester='Fall' and years=2009
intersect
select course_id
from section
where semester='Spring' and years=2010;

select course_id
from section
where semester='Fall' and years=2009 and course_id in(
  select course_id
  from section 
  where semester='Spring' and years=2010
);

select S.course_id
from section S
where S.semester='Fall' and S.years=2009 and exist(
  select *
  from section T
  where T.semester='Spring' and T.years=2010 and T.course_id=S.course_id
)

--选修ID为10111老师开课的学生人数
select count(distinct takes.ID)
from teaches join takes using(course_id, sec_id, semester, year)
where teaches.ID='10111';

select count(distinct takes.ID)
from takes
where (course_id,sec_id,semester,year) in (
  select course_id, sec_id, semester, year
  from teaches
  where teaches.ID=10111
);

--生物系开的所有课的学生
select S.name, S.ID
from student S
where not exist(
  (
    select course_id
    from course
    where dept_name='Biology'
  )
  except
  (
    select course_id
    from takes
    where takes.ID=S.ID
  )
);

--2009年最多开设一次的课程
select course_id
from section S
where unique(
  select course
  from section T
  where S.course_id=T.course_id and T.years=2009
);

select course_id
from section S
where 1>=(
  select count(T.course_id)
  from section T
  where T.course_id=S.course_id and T.years=2009
)


--系平均工资大于42000
select dept_name, avg(salary)
from instructor
group by dept_name
having avg(salary)>42000;

select dept_name, avg_salary
from (
  select dept_name, avg(salary) as avg_salary
  from instructor
  group by dept_name
)
where avg_salary>42000;

--系工资总额最大的系
select dept_name, sum(salary)
from instructor
group by dept_name
having sum(salary)>=(
  select max(sum(salary))
  from instructor
  group by dept_name
);

select dept_name, max(sum_salary)
from (
  select dept_name, sum(salary) as sum_salary
  from instructor
  group by dept_name
);

with dept_total(dept_name, total_salary) as (
  select dept_name, sum(salary)
  from instructor
  group by dept_name
)
select dept_name, total_salary
from dept_total
where total_salary>=(
  select max(total_salary)
  from dept_total
);

--所有工资总额大于所有系平均工资总额的系         
with dept_total(dept_name, value) as(
  select dept_name, sum(salary)
  from instructor
  group by dept_name
),
  dept_total_avg(value) as(
  select avg(value)
  from dept_total
)
select dept_name
from dept_total, dept_total_avg
where dept_total.value>dept_total_avg.value;

--教师数大于12的系名和预算            
select dept_name, budget
from department d
where 12<(
  select count(ID)
  from instructor
  where dept_name=d.dept_name
);

with instructor_count(dept_name, num) as (
  select dept_name, count(ID)
  from instructor
  group by dept_name
)
select dept_name, budget
from instructor_count natural join department
where instructor_count.num>12;
             
--删除
delete from instructor
where dept_name in (
  select dept_name
  from department
  where building='Waston'
);
with avg_salary(value) as (
  select avg(salary)
  from instructor
)
delete from instructor
where salary<avg_salary.value;
             
--插入
insert into student
  select ID, name, dept_name, 0
  from instructor;
             
--更新
update instructor
set salary=salary*1.03
where salary>10000;
update instructor
set salary=salary*1.05
where salary<=10000;
             
--设置学生学分
update student S
set tot_cred = (
  select sum(credits)
  from course natural join takes
  where S.ID=takes.ID and grade is not null and grade,.'F'
);
             
--视图
create view total_salary(dept_name, total_salary) as (
  select dept_name, sum(salary)
  from instructor
  group by dept_name
);

--触发器
create trigger this_check after update on section
referencing new row as nrow
referencing old row as orow
for each row
begin atomic
  --sql语句
end;
