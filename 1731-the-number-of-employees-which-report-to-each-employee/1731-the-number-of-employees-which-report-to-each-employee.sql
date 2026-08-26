SELECT 
    emp.reports_to AS employee_id, 
    mgr.name AS name, 
    COUNT(*) AS reports_count, 
    ROUND(AVG(emp.age), 0) AS average_age
FROM 
    Employees emp
JOIN 
    Employees mgr ON emp.reports_to = mgr.employee_id
GROUP BY 
    emp.reports_to, mgr.name
ORDER BY 
    employee_id;