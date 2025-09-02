# Write your MySQL query statement below
select distinct num as ConsecutiveNums
from(
    select num,
    Lead(num,1) over(order by id)  as next_num,
    Lead(num,2) over(order by id)  as next2_num
    from Logs
) as q
where num=q.next_num and num=q.next2_num;