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
