--数据库sql语句练习
select name,course_id
from instructor natural join teaches;

select name, course_id
from instructor, teaches
where instructor.id=teaches.id;

select name, title
from instructor, teaches, course
where instructor.id=teaches.id and teaches.course_id=course.course_id;

select name, title
from (instructor natural join teaches) join course using(course_id);

select dept_name, avg(salary)
from instructor
group by dept_name
having avg(salary)>42000;

select course_id, sec_id, semester, year, avg(tot_cred)
from student natural join takes
where year=2009
group by course_id, sec_id, semester, year
having count(ID)>2;
