import java.net.*;

public class UDP_SERVER {

    public static void main(String[] args) {
        try {
        	
            DatagramSocket server_Socket = new DatagramSocket(3333);
            
            System.out.println("Server run ");

            boolean shouldRun = true;

            while (shouldRun) {
            	
                byte[] receiveData = new byte[1024];
                
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                
                server_Socket.receive(receivePacket);
                
                String clientMessage = new String(receivePacket.getData(), 0, receivePacket.getLength()).trim();
                
           
                
                InetAddress address = receivePacket.getAddress();
                
                int port = receivePacket.getPort();

                System.out.println("Client (" + "IP: " +  address.getHostAddress() + ", Port : " + port + "): " + clientMessage);
                
                
                if (clientMessage.equalsIgnoreCase("GoodBye")) {
                	
                    System.out.println("Server: Thank you for using our chat service.");
                    String response = "GoodBye";
                    
                    byte[] sendData = response.getBytes();
                    
                    DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, address, port);
                    server_Socket.send(sendPacket);
                    
                    shouldRun = false;
                } else {
                	
                    Thread MUL_clientThread = new Thread(new hANDLE_MUL_CLENT(server_Socket, receivePacket, address, port));
                    MUL_clientThread.start();
                }
            }

            server_Socket.close();

        } catch (Exception e) {
            e.printStackTrace();
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
            byte[] sendData = new byte[1024];
            
            String clientMessage = new String(Packet.getData(), 0, Packet.getLength()).trim();
            
            System.out.println("Client: " + clientMessage);

            String response = "Server: Your message '" + clientMessage + "' has been received.";
            sendData = response.getBytes();
            
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, Address, Port);
            
            server_Socket.send(sendPacket);
            
        } catch (Exception e) {
            System.out.print("Exception : " + e);
        }
    }
}
