import java.net.*;
import java.util.Scanner;

public class UDP_CLIENT2{

    public static void main(String[] args) {
        try {
            DatagramSocket client_socket = new DatagramSocket();
            
            byte[] sd;
            
            byte[] receiveData = new byte[1024];
            
            InetAddress serverAddress = InetAddress.getByName("localhost");
            Scanner input = new Scanner(System.in);
            
            while(true) {
                System.out.print("Enter message (type 'GoodBye' to exit): ");
                String message = input.nextLine();
                sd = message.getBytes();
                
                DatagramPacket sendPacket = new DatagramPacket(sd, sd.length, serverAddress, 3333);
                
                client_socket.send(sendPacket);
                
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                client_socket.receive(receivePacket);
                
                String server_response = new String(receivePacket.getData(), 0, receivePacket.getLength()).trim();
                
                System.out.println("Server response: " + server_response);

                if(server_response.equalsIgnoreCase("GoodBye")) {
                    break;
                }
            }
            
            client_socket.close();
            
        } catch (Exception e) {
            System.out.println("Exception: " + e);
        }
    }
}