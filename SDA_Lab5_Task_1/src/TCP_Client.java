import java.util.*;
import java.io.*;
import java.net.*;
public class TCP_Client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		try {

            Socket client_cocket = new Socket ("localhost",3333);
            
            // Create input stream to read data from server
            DataInputStream din = new DataInputStream(client_cocket.getInputStream());
            // Create output stream to send data to server
            DataOutputStream dout = new DataOutputStream(client_cocket.getOutputStream());

            dout.writeUTF("Client Request to Server to count Vowels");
            
            int response = din.readInt();
			
            System.out.println(" Response from server : " + response + " vowels");

            client_cocket.close();
            din.close();
            dout.close();
           
			
        } catch (Exception e) {
           System.out.print("Exception: " +  e);
        }
		
	}

}
