# Write your MySQL query statement below
SELECT S.user_id,ROUND(IFNULL(AVG(c.action='confirmed'),0),2) AS confirmation_rate  FROM Signups as S
LEFT JOIN Confirmations as c ON S.user_id=c.user_id
GROUP BY S.user_id