
--create
create table employee(
  emp_id int primary key,
  emp_name string,
  age int,
  salary float
);

-- data
INSERT INTO Employee (empid, name, age, salary)
VALUES (101, 'Amit', 28, 15000);

INSERT INTO Employee (empid, name, age, salary)
VALUES (102, 'Neha', 26, 10000);

INSERT INTO Employee (empid, name, age, salary)
VALUES (103, 'Rahul', 35, 12000);

INSERT INTO Employee (empid, name, age, salary)
VALUES (104, 'Priya', 42, 20000);

INSERT INTO Employee (empid, name, age, salary)
VALUES (105, 'Vikas', 24, 8000);

INSERT INTO Employee (empid, name, age, salary)
VALUES (106, 'Anjali', 32, 18000);

INSERT INTO Employee (empid, name, age, salary)
VALUES (107, 'Rohit', 29, 14000);

select * from employee
where salary > (
  select avg(salary) from employee
);

select * from employee
where age = (
  select max(age) from employee
);

SELECT MIN(salary) AS second_lowest_salary
FROM Employee
WHERE salary > (
    SELECT MIN(salary)
    FROM Employee
);

SELECT *
FROM Employee
WHERE age > (
    SELECT AVG(age)
    FROM Employee
)
AND salary < (
    SELECT AVG(salary)
    FROM Employee
);

SELECT DISTINCT salary
FROM Employee
ORDER BY salary DESC
OFFSET 2 ROWS FETCH NEXT 1 ROW ONLY;

-- Q. select highest paid employee in each department
select
