import java.util.*;
import java.io.*;
import java.net.*;

public class TCP_Server {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		 try {
	        
	            ServerSocket Server_Socket = new ServerSocket(3333);
	            
	            System.out.println("Waiting for client ");


	            Socket socket = Server_Socket.accept();
	            
	            System.out.println("Client connected.");

	            // Create input stream to read data from server
	            DataInputStream din = new DataInputStream(socket.getInputStream());
	            // Create output stream to send data to server
	            DataOutputStream dout = new DataOutputStream(socket.getOutputStream());

	     
	            String message = din.readUTF();
	            
	            System.out.println("Message Received from client: " + message);

	       
	            int vowelCount = count_vowels(message);

	          
	            dout.writeInt(vowelCount);

	
	            din.close();
	            dout.close();
	            socket.close();
	            Server_Socket.close();
	            
	        } catch (Exception e) {
	            System.out.print("Exception: " +  e);
	        }
    
	}

	public static int count_vowels(String str) {
		
	    int count = 0;
	    for (char c : str.toCharArray()) {
	      
	        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
	            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
	            count++;
	        }
	        
	    }
	    return count;
	    
	}
}
