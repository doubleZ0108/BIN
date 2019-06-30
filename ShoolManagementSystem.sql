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


--找出所有老师的姓名, 系名, 建筑名--
SELECT name, dept_name, building
FROM instructor, department
WHERE instructor.dept_name = building.dept_name;

SELECT name, dept_name, building
FROM instructor NATURE JOIN building;

--找出所有老师的姓名以及所讲述所有课程的ID--
SELECT name, course_id
FROM instructor, teaches
WHERE instructor.ID = teaches.ID;

--找出老师的姓名以及他们所讲授课程的名字--
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
