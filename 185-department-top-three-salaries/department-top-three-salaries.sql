# Write your MySQL query statement below
select D.name as  Department, Q.name as Employee ,Q.salary as Salary
from Employee E
inner join Department D on D.id= E.departmentId 
inner join (
    select departmentId , name ,salary
    from(
        select departmentId ,name , salary ,dense_rank() 
        OVER (partition by  departmentId order by salary desc) 
        as R
        from Employee
    )as t
    where R=1 or R=2 or R=3
)as Q on Q.departmentId =  E.departmentId and Q.name=E.name;