
import java.net.*;
import java.util.Date;

public class UDP_MUL_CLIENT_SERVER {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {

            DatagramSocket server_Socket = new DatagramSocket(3333);
            
            System.out.println("Server run ");
            
            while (true) {
                
                byte[] receiveData = new byte[1024];
                
               
                DatagramPacket Packet = new DatagramPacket(receiveData, receiveData.length);
                
  
                server_Socket.receive(Packet);
                
     
                InetAddress Address = Packet.getAddress();
                
                int Port = Packet.getPort();
                


                Thread MUL_clientThread = new Thread(new hANDLE_MUL_CLENT(server_Socket, Packet, Address, Port));
                
                MUL_clientThread.start();
            }
		}catch (Exception e) {
	        	System.out.print("Exception : " + e);
	        
	        }
	}

}


class hANDLE_MUL_CLENT implements Runnable {
	
	public DatagramSocket server_Socket;
	public DatagramPacket Packet;
    public InetAddress Address;
    public int Port;

    public hANDLE_MUL_CLENT(DatagramSocket server_Socket, DatagramPacket Packet, InetAddress Address, int Port) {
        this.server_Socket = server_Socket;
        this.Packet = Packet;
        this.Address = Address;
        this.Port = Port;
    }


    public void run() {
        try {
        	
        	 String Time = new Date().toString();
        	 
        	   String response = "Server time: " + Time + " for client at " + Address + ", " + Port;
        	   
        	  byte[] Data = response.getBytes();
        	  
            DatagramPacket sendPacket = new DatagramPacket(Data, Data.length, Address, Port);

            server_Socket.send(sendPacket);
            
            System.out.println("Response is sent to client at " + Address + ", " + Port);
            
        } catch (Exception e) {
        	System.out.print("Exception : " + e);
	        
        }
    }
}
