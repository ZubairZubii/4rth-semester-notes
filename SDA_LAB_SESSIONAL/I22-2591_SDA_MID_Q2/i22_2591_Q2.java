import java.sql.*;

public class i22_2591_Q2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Connection myconn = null;
		Statement mystmt = null;
		ResultSet myRs = null;
		String user = "root";
		String pass = "2250154*";
		
		try {
		
			myconn =  DriverManager.getConnection( "jdbc:mysql:// localhost:3306", user, pass);

		System.out.println("Connected Successfully");
		
		mystmt = myconn.createStatement();
		
	//	mystmt.execute("CREATE DATABASE HOSPITAL_DATABASE_MANAGEMENT");
		
		System.out.println("Create database Successfully");
		
		
		mystmt.execute("USE HOSPITAL_DATABASE_MANAGEMENT");
	
		String Patient_table = "CREATE TABLE Patient ("
				+ "    PatientID INT PRIMARY KEY AUTO_INCREMENT,"
				+ "    Name VARCHAR(25),"
				+ "    Age INT,"
				+ "    ContactInformation VARCHAR(25),"
				+ "    Symptoms TEXT)";
		
	//	mystmt.executeUpdate(Patient_table);
		System.out.println("patient table created  Successfully");
		
		
		String Doctor_Table = "CREATE TABLE Doctor ("
				+ "    DoctorID INT PRIMARY KEY AUTO_INCREMENT,"
				+ "    Name VARCHAR(25),"
				+ "    Specialization VARCHAR(25),"
				+ "    ContactInformation VARCHAR(25))";
		
		//mystmt.executeUpdate(Doctor_Table);
		System.out.println("Doctor table created  Successfully");
      
		String Appointment_Table = "CREATE TABLE Appointment ("
		        + "    AppointmentID INT PRIMARY KEY AUTO_INCREMENT,"
		        + "    PatientID INT,"
		        + "    DoctorID INT,"
		        + "    Date DATE,"
		        + "    Time TIME,"
		        + "    Status VARCHAR(25) DEFAULT 'Scheduled')";

		
		//mystmt.executeUpdate(Appointment_Table);
	
		
		System.out.println("Appointment_Table created  Successfully");
      
		
		String ReceptionDesk_Table = "CREATE TABLE ReceptionDesk("
				+ "ClerkID INT PRIMARY KEY AUTO_INCREMENT , "
				+ "Name VARCHAR(25),ContactInformation VARCHAR(25))";
		
		
		//mystmt.executeUpdate(ReceptionDesk_Table);
		System.out.println("ReceptionDesk_Table created  Successfully");
      
		
		String HospitalAdministrator_Table = "CREATE TABLE HospitalAdministrator ("
				+ "    AdminID INT PRIMARY KEY AUTO_INCREMENT,"
				+ "    Name VARCHAR(25),"
				+ "    ContactInformation VARCHAR(25))";
		
		
		//mystmt.executeUpdate(HospitalAdministrator_Table);
		System.out.println("HospitalAdministrator_Table created  Successfully");
      
		
		String AvailabilitySchedule_Table = "CREATE TABLE AvailabilitySchedule ("
				+ "    AvailabilityID INT PRIMARY KEY AUTO_INCREMENT,"
				+ "    DoctorID INT,"
				+ "    Date DATE,"
				+ "    TimeFrom TIME,"
				+ "    TimeTo TIME)";
		
		
		//mystmt.executeUpdate(AvailabilitySchedule_Table);

		System.out.println("AvailabilitySchedule_Table created  Successfully");
      
		
		
		
	    String insertPatient1 = "INSERT INTO Patient (Name, Age, ContactInformation, Symptoms) VALUES ('Zubair Ali', 30, '1234567890', 'Fever')";
        String insertPatient2 = "INSERT INTO Patient (Name, Age, ContactInformation, Symptoms) VALUES ('Ali Rizwan', 25, '9876543210', 'Headache')";
      //  mystmt.executeUpdate(insertPatient1);
       // mystmt.executeUpdate(insertPatient2);
        System.out.println("Values inserted into Patient table");
		
        
        String insertDoctor1 = "INSERT INTO Doctor (Name, Specialization, ContactInformation) VALUES ('Dr. Zanoon', 'Cardiologist', '0321-1545234')";
        String insertDoctor2 = "INSERT INTO Doctor (Name, Specialization, ContactInformation) VALUES ('Dr. Bilal', 'Dermatologist', '0320-5674548')";
       // mystmt.executeUpdate(insertDoctor1);
        //mystmt.executeUpdate(insertDoctor2);
        System.out.println("Values inserted into Doctor table");
        
        String insertAppointment1 = "INSERT INTO Appointment (PatientID, DoctorID, Date, Time) VALUES (1, 1, '2024-03-23', '10:00')";
        String insertAppointment2 = "INSERT INTO Appointment (PatientID, DoctorID, Date, Time) VALUES (2, 2, '2024-03-24', '11:00')";
        //mystmt.executeUpdate(insertAppointment1);
        //mystmt.executeUpdate(insertAppointment2);
        System.out.println("Values inserted into Appointment table");
        
        
        String insertReceptionDesk1 = "INSERT INTO ReceptionDesk (Name, ContactInformation) VALUES ('Uzair', '0321-7654321')";
        String insertReceptionDesk2 = "INSERT INTO ReceptionDesk (Name, ContactInformation) VALUES ('Haq', '0321-4567893')";
       // mystmt.executeUpdate(insertReceptionDesk1);
       // mystmt.executeUpdate(insertReceptionDesk2);
        System.out.println("Values inserted into ReceptionDesk table");
        
        
        String insertHospitalAdmin1 = "INSERT INTO HospitalAdministrator (Name, ContactInformation) VALUES ('Dansih', '0321-9402853')";
        String insertHospitalAdmin2 = "INSERT INTO HospitalAdministrator (Name, ContactInformation) VALUES ('Haseeb', '0320-8436896')";
        //mystmt.executeUpdate(insertHospitalAdmin1);
        //mystmt.executeUpdate(insertHospitalAdmin2);
        System.out.println("Values inserted into HospitalAdministrator table");

        String insertAvailability1 = "INSERT INTO AvailabilitySchedule (DoctorID, Date, TimeFrom, TimeTo) VALUES (1, '2024-03-23', '09:00', '17:00')";
        String insertAvailability2 = "INSERT INTO AvailabilitySchedule (DoctorID, Date, TimeFrom, TimeTo) VALUES (2, '2024-03-24', '10:00', '18:00')";
        //mystmt.executeUpdate(insertAvailability1);
        //mystmt.executeUpdate(insertAvailability2);        
        System.out.println("Values inserted into AvailabilitySchedule  table");

        
        String updatePatient = "UPDATE Patient SET Age = 26 WHERE PatientID = 1";
       // mystmt.executeUpdate(updatePatient);
        System.out.println("Updated age for PatientID 1 in Patient table");

        // Update values in Doctor table
        String updateDoctor = "UPDATE Doctor SET ContactInformation = '0322-1223344' WHERE DoctorID = 1";
        //mystmt.executeUpdate(updateDoctor);
        System.out.println("Updated ContactInformation for DoctorID 1 in Doctor table");

        // Update values in Appointment table
        String updateAppointment = "UPDATE Appointment SET Status = 'Cancelled' WHERE AppointmentID = 1";
      //  mystmt.executeUpdate(updateAppointment);
        System.out.println("Updated Status for AppointmentID 1 in Appointment table");

        // Update values in ReceptionDesk table
        String updateReceptionDesk = "UPDATE ReceptionDesk SET ContactInformation = '0321-4444552' WHERE ClerkID = 1";
        //mystmt.executeUpdate(updateReceptionDesk);
        System.out.println("Updated ContactInformation for ClerkID 1 in ReceptionDesk table");

        // Update values in HospitalAdministrator table
        String updateHospitalAdmin = "UPDATE HospitalAdministrator SET Name = 'Ubaid' WHERE AdminID = 1";
        //mystmt.executeUpdate(updateHospitalAdmin);
        System.out.println("Updated Name for AdminID 1 in HospitalAdministrator table");

        // Update values in AvailabilitySchedule table
        String updateAvailability = "UPDATE AvailabilitySchedule SET TimeFrom = '09:30', TimeTo = '18:30' WHERE AvailabilityID = 1";
        mystmt.executeUpdate(updateAvailability);
        //System.out.println("Updated TimeFrom and TimeTo for AvailabilityID 1 in AvailabilitySchedule table");
        
        
      
        String deletePatient = "DELETE FROM Patient WHERE PatientID = 1";
       // mystmt.executeUpdate(deletePatient);
        System.out.println("Deleted record with PatientID 1 from Patient table");

        // Delete a record from Doctor table
        String deleteDoctor = "DELETE FROM Doctor WHERE DoctorID = 1";
        //mystmt.executeUpdate(deleteDoctor);
        System.out.println("Deleted record with DoctorID 1 from Doctor table");

        // Delete a record from Appointment table
        String deleteAppointment = "DELETE FROM Appointment WHERE AppointmentID = 1";
        //mystmt.executeUpdate(deleteAppointment);
        System.out.println("Deleted record with AppointmentID 1 from Appointment table");

        // Delete a record from ReceptionDesk table
        String deleteReceptionDesk = "DELETE FROM ReceptionDesk WHERE ClerkID = 1";
        //mystmt.executeUpdate(deleteReceptionDesk);
        System.out.println("Deleted record with ClerkID 1 from ReceptionDesk table");

        // Delete a record from HospitalAdministrator table
        String deleteHospitalAdmin = "DELETE FROM HospitalAdministrator WHERE AdminID = 1";
        //mystmt.executeUpdate(deleteHospitalAdmin);
        System.out.println("Deleted record with AdminID 1 from HospitalAdministrator table");

        // Delete a record from AvailabilitySchedule table
        String deleteAvailability = "DELETE FROM AvailabilitySchedule WHERE AvailabilityID = 1";
        //mystmt.executeUpdate(deleteAvailability);
        System.out.println("Deleted record with AvailabilityID 1 from AvailabilitySchedule table");
        
        
		myconn.close();
		
		} catch (Exception exc) {
		exc.printStackTrace();
		}
	}

}
