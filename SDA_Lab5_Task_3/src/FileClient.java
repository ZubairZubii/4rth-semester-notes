import java.net.*;
import java.io.*;

public class FileClient {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		try {
            Socket socket = new Socket("localhost", 3333);

            
            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());

            
            File file = new File("C:\\Users\\Zubair\\Documents\\ZU.txt");

            dos.writeUTF(file.getName());

            FileInputStream fi = new FileInputStream(file);
                byte[] b = new byte[1024];
                int bytesRead;
                while ((bytesRead = fi.read(b)) != -1) {
                    dos.write(b, 0, bytesRead);
                }
            

            System.out.println("File sent successfully.");

         
            fi.close();
            dos.close();
            socket.close();
        } catch (Exception e) {
          System.out.print("Exception " + e);
        }
		
	}

}
