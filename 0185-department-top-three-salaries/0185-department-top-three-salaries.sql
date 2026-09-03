WITH RankedEmployees AS (
    SELECT 
        e.name AS Employee,
        e.salary,
        e.departmentId,
        DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS salary_rank
    FROM Employee e
)
SELECT 
    d.name AS Department,
    re.Employee,
    re.salary
FROM RankedEmployees re
JOIN Department d ON re.departmentId = d.id
WHERE re.salary_rank <= 3
ORDER BY d.name, re.salary DESC, re.Employee;