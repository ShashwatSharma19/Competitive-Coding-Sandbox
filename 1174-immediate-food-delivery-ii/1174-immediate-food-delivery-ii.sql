WITH first_orders AS (
    SELECT customer_id, MIN(order_date) AS first_date
    FROM Delivery
    GROUP BY customer_id
),
first_deliveries AS (
    SELECT d.customer_id,
           CASE WHEN d.order_date = d.customer_pref_delivery_date THEN 1 ELSE 0 END AS is_immediate
    FROM Delivery d
    JOIN first_orders f 
        ON d.customer_id = f.customer_id 
        AND d.order_date = f.first_date
)
SELECT ROUND(AVG(is_immediate) * 100, 2) AS immediate_percentage
FROM first_deliveries;