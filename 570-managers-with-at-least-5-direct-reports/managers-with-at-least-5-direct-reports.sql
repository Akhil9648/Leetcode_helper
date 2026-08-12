# Write your MySQL query statement below
SELECT E1.name FROM Employee as E1
WHERE E1.id IN (
    SELECT E2.managerId FROM Employee as E2
    GROUP BY E2.managerId
    HAVING count(E2.managerId)>=5
)