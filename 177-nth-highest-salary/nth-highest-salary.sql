CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE K INT;
  set K=N-1;
  RETURN (
      # Write your MySQL query statement below.
    select salary 
    from(
        select Distinct salary 
        from Employee
        order by salary Desc
        limit 1 offset K
    )as q
  );
END