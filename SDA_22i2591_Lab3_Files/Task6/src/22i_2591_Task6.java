import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.Comparator;


class Employee {
	
    private String Name;
    private double Salary;

    public Employee(String Name, double Salary) {
        this.Name = Name;
        this.Salary = Salary;
    }

    public String getName() {
        return Name;
    }

    public double getSalary() {
        return Salary;
    }

 
}

public class Task6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		 List<Employee> employees = new ArrayList<>();
	        employees.add(new Employee("Zubair", 20));
	        employees.add(new Employee("Ali", 10));
	        employees.add(new Employee("Bilal", 40));
	   

	        System.out.println("Before Sorted employee list :");
	        for (Employee employee : employees) {
	        	System.out.print("Employee :");
	            System.out.print(employee.getName());
	            System.out.println(" " + employee.getSalary());
	        }
	        
	         Collections.sort(employees, Comparator.comparing(Employee::getSalary));
	      /* Collections.sort(employees ,new Comparator<Employee>(){
	        	
	        	public int compare(Employee e1, Employee e2) {
	        		return Double.compare(e1.getSalary(),e2.getSalary());
	        	    }
	              }
	        		
        		);*/
	        
	        
	        
	      
	        System.out.println("Sorted employee list ascending order on Basis of Salary:");
	        
	        for (Employee employee : employees) {
	        	System.out.print("Employee :");
	            System.out.print(employee.getName());
	            System.out.println(" " + employee.getSalary());
	        }
	        
	}

}



