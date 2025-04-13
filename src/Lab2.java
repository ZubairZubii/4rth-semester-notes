
import java.util.ArrayList;


class Person{
	
	public String Name;
	public String Address;
	
	public Person( ){
	
	}
	
	public Person(String name, String Add ){
		Name = name;
		Address = Add;
	}
}

class Student extends Person{
	
	ArrayList<String> Courses = new ArrayList<>();;
	ArrayList<Integer> Grades  = new ArrayList<>();;
	
	public Student(String n,String Ad) {
		super(n,Ad);
	}
	
	public void Addcourses(String course,int grade) {
		
		if(Courses.size() < 30) {
			
			Courses.add(course);
			Grades.add(grade);
			
			
			
		}
		else
		{
			System.out.println("Size not allowed");
		}
		
		
		
	}
	
	public void Average() {
		int sum=0;
		for(int i=0;i<Grades.size();i++) {
			sum += Grades.get(i);
		}
		
		Double Average =  (double) sum / Grades.size();
		System.out.println("Average of Grade" +  Average);
	
		
	}
	
	public void Print() {
		System.out.println("Student Name: " + Name);
	    System.out.println("Student Address: " + Address);
		for(int i=0;i<Courses.size();i++) {
			
		    System.out.println("Courses and Grades:");
		    System.out.println("Course: " + Courses.get(i) + ", Grade: " + Grades.get(i));
		}
         Average();
		
         System.out.println("______________");
	
	}
}



class Professor extends Person{
	
	ArrayList<String> Courses_Taught = new ArrayList<>();;
	
	Professor(){
		
	}
	
	
    Professor(String Name,String Add){
		super(Name,Add);
	}
	
	public void addTaught(String course) {
		
		if(Courses_Taught.size() < 5) {
			Courses_Taught.add(course);
		}
		else
			System.out.print("No more course Added");
		
	}
	
	
	public void removeTaught(String course) {
		
		if(Courses_Taught.contains(course)) {
			Courses_Taught.remove(course);
		}
		else
			System.out.println("Course not present");
	
		
	}
	
	
	public void  Print_CourseTaught() {
		 System.out.println("Professor Name: " + Name);
	     System.out.println("Professor Address: " + Address);
	        
	for(int i=0;i<Courses_Taught.size();i++) {
		   
	        System.out.print("Courses Taught:");
			System.out.println(Courses_Taught.get(i));
	
		}
	   System.out.println("______________");
	}
	
	
}






public class Lab2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Students Data: ");
		
	Student s1= new Student("Zubair", "G11");
		
	s1.Addcourses("Prog", 90);
	s1.Addcourses("SDA", 40);
	
	s1.Print();

	System.out.println("Professor Data Before Remove: ");
	Professor p1 = new Professor("Professor" ,"H11");
	p1.addTaught("Prog");
	p1.addTaught("LA");
	p1.Print_CourseTaught();
	
	System.out.println("Professor Data After Remove : ");
	
	p1.removeTaught("Prog");
	p1.Print_CourseTaught();
	
	}

}
