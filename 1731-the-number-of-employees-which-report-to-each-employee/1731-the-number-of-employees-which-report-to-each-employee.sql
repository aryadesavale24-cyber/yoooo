# Write your MySQL query statement below
select e.employee_id as employee_id,
e.name as name,
 count(e1.employee_id) reports_count,
 round(avg(e1.age)) as average_age
from employees e
join employees e1
on e.employee_id=e1.reports_to 
group by e.employee_id,e.name
order by e.employee_id


