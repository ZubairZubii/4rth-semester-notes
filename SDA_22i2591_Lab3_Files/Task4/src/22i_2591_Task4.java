
class myQueue {
	 
    public int[] queue;
    public int capacity;
    public int size;
    public int front;
    public int rear;
    
   

    public myQueue(int capacity) {
    	
        this.capacity = capacity;
        this.queue = new int[capacity];
        this.front = 0;
        this.rear = -1;
        this.size = 0;
        
    }

    
    public void enqueue(int element) {
    	
        if (isFull()) {
          System.out.println("Queue is Full");
        }
        
        rear = (rear + 1) % capacity;
        queue[rear] = element;
        size++;
        
    }

   
    public int dequeue() {
    	
        if (isEmpty()) {
        	
        	 System.out.println("Queue is Empty");
        	 
        }
        
        int removedElement = queue[front];
        front = (front + 1) % capacity;
        size--;
        
        return removedElement;
        
    }
    
    
    public boolean isEmpty() {
    	
        return size == 0;
        
    }
    

    public boolean isFull() {
    	
        return size == capacity;
        
    }
    

    public int rear() {
    	
        if (isEmpty()) {
        	
        	System.out.println("Queue is Empty");
        	
        }
        
        return queue[rear];
    }


}

public class Task4 {

	public static void main(String[] args) {

		 myQueue queue = new myQueue(5);

	        queue.enqueue(20);
	        queue.enqueue(50);
	        queue.enqueue(70);

	        System.out.println("Dequeued element: " + queue.dequeue());

	        System.out.println("Is queue empty? " + queue.isEmpty());
	
	        System.out.println("Rear element: " + queue.rear());

	}

}
