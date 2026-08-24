# Write your MySQL query statement below
SELECT MAX(num) AS num
FROM(
    SELECT num
    FROM MyNumbers
    GROUP by num
    HAVING COUNT(*)=1
    ) AS single_numbers;