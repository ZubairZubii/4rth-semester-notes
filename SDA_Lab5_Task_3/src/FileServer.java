import java.net.*;
import java.io.*;

public class FileServer {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		  try {
			  
	            ServerSocket serverSocket = new ServerSocket(3333);
	            System.out.println("Waiting for clients ");

	         
	                Socket socket = serverSocket.accept();
	                System.out.println("Client connected.");

	                DataInputStream dis = new DataInputStream(socket.getInputStream());

	      
	                String fileName = dis.readUTF();
                    System.out.println("Receiving file: " + fileName);

                    FileOutputStream fo = new FileOutputStream("C:\\Users\\Zubair\\Documents\\NewLaptop\\received\\" + fileName);

                    byte[] b = new byte[1024];
                    int bytesRead;
                    while ((bytesRead = dis.read(b)) != -1) {
                        fo.write(b, 0, bytesRead);
                    }
	                System.out.println("File received successfully.");

	                // Close streams and socket
	                fo.close();
	                dis.close();
	                socket.close();
	            
	        } catch (Exception e) {
	        	  System.out.print("Exception " + e);
	        }
		  
	}

}
