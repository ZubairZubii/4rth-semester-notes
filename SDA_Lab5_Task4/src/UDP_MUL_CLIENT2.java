
import java.net.*;
import java.util.Scanner;

public class UDP_MUL_CLIENT2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 try {
	            DatagramSocket client_socket = new DatagramSocket();
	            InetAddress serverAddress = InetAddress.getByName("localhost");
	            byte[] sendData = new byte[1024];
	            Scanner scanner = new Scanner(System.in);

	            while (true) {
	                // Send request to the server
	                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverAddress, 3333);
	                client_socket.send(sendPacket);

	                // Receive response from the server
	                byte[] receiveData = new byte[1024];
	                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
	                client_socket.receive(receivePacket);

	              
	                String serverTime = new String(receivePacket.getData());
	                System.out.println("Server time (Client 2): " + serverTime.trim());

	            
	                System.out.println("Press Enter to continue or type 'quit' to exit:");
	                String input = scanner.nextLine();
	                if (input.equalsIgnoreCase("quit")) {
	                    break;
	                }
	            }

	        
	            scanner.close();
	            client_socket.close();
	        } catch (Exception e) {
	            System.out.print("Exception : " + e);
	        }
	}

}
