# Write your MySQL query statement below
SELECT max(salary) as SecondHighestSalary FROM (
    SELECT DISTINCT(Salary)  FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) t