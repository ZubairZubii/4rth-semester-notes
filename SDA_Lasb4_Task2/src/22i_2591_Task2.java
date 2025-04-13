
import java.sql.*;

public class Task2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Connection myconn = null;
		Statement mystmt = null;
		ResultSet myRs = null;
		String user = "root";
		String pass = "2250154*";
		
		try {
		myconn =

		DriverManager.getConnection( "jdbc:mysql:// localhost:3306/", user, pass);

		System.out.println("Connected Successfully");
		
		mystmt = myconn.createStatement();
		 mystmt.execute("Use Student");
		
		 // mystmt.execute("CREATE DATABASE Student");
	
		String table = "CREATE TABLE Students (" +
                 "id INTEGER(4) PRIMARY KEY," +
                 "name VARCHAR(9)," +
                 "age INTEGER(4)," +
                 "grade VARCHAR(9))";
		      System.out.println("Table created successfully");
	//	 mystmt.execute(table);
		 
		 
		 String insertkey = "INSERT INTO Students VALUES " + 
                 "(1, 'Zubair', 18, 'B')," +
                 "(2, 'Ali', 19, 'B')," +
                 "(3, 'Bilal', 20, 'A')," + // Added a comma here
                 "(4, 'Uzair', 19, 'A')";

     // mystmt.execute(insertkey);
		 mystmt.execute("Insert INTO Studennts Value" +  "(5,'Zubair',15'B')");
      System.out.println("Insert successfully");
      
      
       
       myRs = mystmt.executeQuery("Select * from Students");
       while (myRs.next()) {
    	  int id =  myRs.getInt("id");
    	  String name =  myRs.getString("name");
    	  int age =  myRs.getInt("age");
    	  String grade =  myRs.getString("grade");
       System.out.println("id " + id + ",name "  + name + ",age " +age + ",grade " + grade  );
       
       }
       System.out.println("Data inserted successfully");
		 
    
      String deletekey = "DELETE FROM Students WHERE id = 1";
      mystmt.execute(deletekey);
      System.out.println("Record deleted successfully");

      
      String updatekey = "update Students SET name = 'Bilal'  WHERE name = 'Alice' ";
      mystmt.execute(updatekey);
      System.out.println("Update successfully");
      
		myconn.close();
		} catch (Exception exc) {
		exc.printStackTrace();
		}

	}

}
