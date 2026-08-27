# Write your MySQL query statement below
select ifnull(max(num),null) as num
from mynumbers
where num in (select num
from myNumbers
group by num
having count(*)=1
)



