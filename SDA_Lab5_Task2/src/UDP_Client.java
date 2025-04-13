import java.net.*;


public class UDP_Client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		 try {
	            
	            DatagramSocket client_socket = new DatagramSocket();
	            
	           
	            InetAddress serverAddress = InetAddress.getByName("localhost");
	            
	           
	            byte[] sd = new byte[1024];
	            
	
	            DatagramPacket snedpacket = new DatagramPacket(sd, sd.length, serverAddress, 3333);
	            
	         
	            client_socket.send(snedpacket);
	            
	          
	            byte[] receiveData = new byte[1024];
	            
	            
	            DatagramPacket receivepacket = new DatagramPacket(receiveData, receiveData.length);
	            
	          
	            client_socket.receive(receivepacket);
	            
	            // Convert received data to string
	            
	            
	            String serverTime = new String(receivepacket.getData());
	            
	         
	            System.out.println(" Server time : " + serverTime.trim());
	            
	   
	            client_socket.close();
	            
	        } catch (Exception e) {
	        	System.out.print("Exception : " + e);
	        
	        }
		
		

		
		
	}

}
