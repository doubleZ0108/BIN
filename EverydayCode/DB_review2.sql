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
