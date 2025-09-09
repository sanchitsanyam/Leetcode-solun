# Write your MySQL query statement below
with t as(
    select id ,email , dense_rank()
    over(partition by email order by id )
    as r from Person
)
Delete from person 
where id in(
    select id from 
    t where t.r!=1
);