# Write your MySQL query statement below
SELECT * from Cinema
WHERE description != "boring" and id%2=1
ORDER BY rating DESC