import java.util.*;

public class Task3 {

    public static void main(String[] args) {
        // Creating a stack
        Stack<Integer> stack = new Stack<>();

        // Pushing elements onto the stack
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);

      
        int topElement = stack.peek();
        System.out.println("Top element of the stack: " + topElement);

        
        int bottomElement = stack.peek(); 
        while (!stack.empty()) {
            bottomElement = stack.pop(); 
        }

        System.out.println("Bottom element of the stack: " + bottomElement);
    }
}
