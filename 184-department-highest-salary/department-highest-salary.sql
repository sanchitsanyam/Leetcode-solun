# Write your MySQL query statement below
select D.name as Department , E.name as Employee ,q.maxSalary as Salary 
from Employee E
inner join  Department D ON E.departmentId=D.id
inner join (select max(salary) as maxSalary , departmentId from Employee group by departmentId  ) as q on
q.departmentId= E.departmentId and q.maxSalary=E.salary;
