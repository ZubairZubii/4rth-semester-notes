Select first_name, COUNT(salary) as Count_Salary from employees Where first_name LIKE'J%'or first_name LIKE 'A%' Group By first_name Having COUNT(salary) > 1 Order By Count_Salary ASC;


Select* from employees;