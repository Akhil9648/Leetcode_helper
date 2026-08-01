# Write your MySQL query statement below
SELECT S.student_id ,S.student_name,sub.subject_name,COUNT(E.student_id) as attended_exams 
FROM Students S CROSS JOIN Subjects sub LEFT JOIN Examinations E on S.student_id=E.student_id 
AND sub.subject_name=E.subject_name
GROUP BY S.student_id,S.student_name,sub.subject_name 
ORDER BY S.student_id,sub.subject_name  