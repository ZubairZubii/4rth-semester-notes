import java.util.*;

public class Task1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		LinkedList<Integer> linklist = new LinkedList<>();
		
		
		linklist.add(10);
	    linklist.add(20);
		linklist.add(30);
		linklist.add(40);
		linklist.add(50);
		

		System.out.println("LinkedList Before INSERT first element:" +linklist);
		
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter value that insert first :");
		int first = input.nextInt(); 
		linklist.addFirst(first);
		System.out.println("Enter value that insert last :");
		int last = input.nextInt(); 
		linklist.addLast(last);
		
		
		System.out.println("LinkedList after INSERT first element:" +linklist);
		
		
		
	}

}


