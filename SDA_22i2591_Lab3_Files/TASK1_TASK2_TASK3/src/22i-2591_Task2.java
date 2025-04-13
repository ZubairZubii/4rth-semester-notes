import java.util.LinkedList;
import java.util.Scanner;

public class Task2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub


		LinkedList<Integer> linklist = new LinkedList<>();
		
		System.out.println("Enter the starting element from which start:");
		
		Scanner input = new Scanner(System.in);
		int start_element = input.nextInt();
		
		linklist.add(10);
	    linklist.add(20);
	    
		linklist.add(30);
		linklist.add(40);
		linklist.add(50);
		
        for(int i=start_element - 1; i < linklist.size();i++) {
        	System.out.println("LinkedList element:" +linklist.get(i));
        }
		
		
		
		
	}

}
