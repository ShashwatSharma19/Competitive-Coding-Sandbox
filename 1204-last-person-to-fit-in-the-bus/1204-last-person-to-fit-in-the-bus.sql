SELECT t.person_name
FROM (
    SELECT 
        person_name,
        turn,
        SUM(weight) OVER (ORDER BY turn ASC) AS total_weight
    FROM Queue
) t
WHERE t.total_weight <= 1000
ORDER BY t.turn DESC
LIMIT 1;
