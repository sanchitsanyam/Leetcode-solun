# Write your MySQL query statement below
select *
from
    (select  M.request_at as Day , ROUND(Avg(M.t),2) as `Cancellation Rate` 
    from    
        (select
            R.id,
            R.request_at,
            CASE WHEN R.status="completed" THEN 0 else 1 END as t
        from    
            (select Q.id,Q.status, Q.request_at
            from 
            (    select id,client_id,driver_id,status,request_at
                from Trips T
                join Users U on U.users_id=T.driver_id
                where U.banned!="Yes" ) as Q
            join Users U on U.users_id=Q.client_id
            where U.banned!="Yes") as R) as M
    group by  M.request_at )as D   
where D.day  between "2013-10-01" and "2013-10-03"
order by D.day