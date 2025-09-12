# Write your MySQL query statement below
select q.tid as Id
from(
    select id,temperature ,recordDate,Lead(id,1)over(order by recordDate ASC) as tid,Lead(recordDate,1)over(order by recordDate ASC) as tdate,Lead     (temperature,1)   over(order by recordDate ASC) as temp
    from Weather
    
) as q
where DATEDIFF(tdate,recordDate)=1 and q.temp>q.temperature

 
