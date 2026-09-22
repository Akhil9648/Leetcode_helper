# Write your MySQL query statement below
select max(salary) as SecondHighestSalary  from(
SELECT salary , dense_rank() OVER (
    ORDER BY salary DESC
) as rnk

FROM Employee
) t
where rnk=2
