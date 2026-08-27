# Write your MySQL query statement below
select c.customer_id
from customer  c
group by customer_id
having COUNT(DISTINCT c.product_key)=(SELECT COUNT(*) FROM Product)

