
import java.util.Scanner;

public class CRMS {

	public static void main(String[] args) {
		Car_Rental_Management carRaceManagement = new Car_Rental_Management();
        Scanner scanner = new Scanner(System.in);
      //  scanner.close(); // Close the scanner
        while (true) {
            // Display menu options
        	System.out.println("\n=== Car Rental Management System ===");
        	System.out.println("1. Add a new car");
        	System.out.println("2. Display available cars");
        	System.out.println("3. Remove a car");
        	System.out.println("4. Add a new renter");
        	System.out.println("5. Display renter details");
        	System.out.println("6. Remove a renter");
        	System.out.println("7. Rent a car");
        	System.out.println("8. Display rental details");
        	System.out.println("9. Calculate total rental cost");
        	System.out.println("10. Return a car");
        	System.out.println("11. Exit");
        	System.out.print("Enter your choice: ");
        	int choice = scanner.nextInt();
        	scanner.nextLine();
        	System.out.println("");
            System.out.println("----------------------------------------");
            
            switch (choice) {
                case 1:
                    // Add new car
                    System.out.println("Enter car details:");
                    System.out.print("Car ID: ");
                    int carID = scanner.nextInt();
                    scanner.nextLine(); 
                    System.out.print("Brand: ");
                    String brand = scanner.nextLine();
                    System.out.print("Model: ");
                    String model = scanner.nextLine();
                    System.out.print("Year: ");
                    int year = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Rental Fee: ");
                    double rentalFee = scanner.nextDouble();
                    scanner.nextLine(); 
                    System.out.print("Plate Number: ");
                    String plateNumber = scanner.nextLine();
                    System.out.println("Is it a Compact Car? (Y/N): ");
                    char isCompact = scanner.next().charAt(0);
                    if (isCompact == 'Y' || isCompact == 'y') {
                        
                        Compact_Car cc = new Compact_Car(carID, brand, model, year, rentalFee, plateNumber);
                        carRaceManagement.addCar(cc);
                    } else 
                    {
                        System.out.println("Is it an SUV or Luxury Car? (S/L): ");
                        char isSUVorLuxury = scanner.next().charAt(0);
                        if (isSUVorLuxury == 'S' || isSUVorLuxury == 's') {
                        
                            carRaceManagement.addCar(new SUV_CAR(carID, brand, model, year, rentalFee, plateNumber));
                        } else if (isSUVorLuxury == 'L' || isSUVorLuxury == 'l')
                        	{
                         
                            carRaceManagement.addCar(new Luxury_Car(carID, brand, model, year, rentalFee, plateNumber));
                        }
                    }
                    break;
                case 2:
                    // Display available cars
                    carRaceManagement.display_All_AvailableCars();
                    break;
                case 3:
                    // Remove a car
                    System.out.print("Enter the plate number of the car to remove: ");
                    String plateToRemove = scanner.nextLine();
                    Car carToRemove = null;
                    for (Car car : carRaceManagement.getCars()) {
                        if (car.getPlateNumber().equals(plateToRemove)) {
                            carToRemove = car;
                            break;
                        }
                    }
                    if (carToRemove != null) {
                        carRaceManagement.removeCar(carToRemove);
                    } else {
                        System.out.println("Car not found with the provided plate number.");
                    }
                    break;
                case 4:
                	 // Add new renter
                    System.out.println("Enter renter details:");
                    System.out.print("Renter ID: ");
                    int renterID = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Name: ");
                    String name = scanner.nextLine();
                    System.out.print("Email: ");
                    String email = scanner.nextLine();
                    System.out.print("Phone Number: ");
                    String phoneNumber = scanner.nextLine();
                    System.out.print("Address: ");
                    String address = scanner.nextLine();
                    
                    System.out.println("Select renter type:");
                    System.out.println("1. Regular");
                    System.out.println("2. Frequent");
                    System.out.println("3. Corporate");
                    int renterTypeChoice = scanner.nextInt();
                    scanner.nextLine(); 
                    
                    Renter newRenter = null;
                    switch (renterTypeChoice) {
                        case 1:
                            newRenter = new Regular_Renter(renterID, name, email, phoneNumber, address);
                            break;
                        case 2:
                            newRenter = new Frequent_Renter(renterID, name, email, phoneNumber, address);
                            break;
                        case 3:
                            newRenter = new Cooperate_Renter(renterID, name, email, phoneNumber, address);
                            break;
                        default:
                            System.out.println("Invalid choice!");
                            break;
                    }
                    
                    if (newRenter != null) {
                        carRaceManagement.addRenter(newRenter);
                    }
                    break;
                case 5:
                    // Display renter details
                    carRaceManagement.displayRenters();
                    break;
                case 6:
                    // Remove a renter
                    System.out.print("Enter the email of the renter to remove: ");
                    String emailToRemove = scanner.nextLine();
                    Renter renterToRemove = null;
                    for (Renter renter : carRaceManagement.getRenters()) {
                        if (renter.getEmail().equals(emailToRemove)) {
                            renterToRemove = renter;
                            break;
                        }
                    }
                    if (renterToRemove != null) {
                        carRaceManagement.removeRenter(renterToRemove);
                    } else {
                        System.out.println("Renter not found with the provided email.");
                    }
                    break;
                case 7:
                    // Rent a car
                    System.out.print("Enter the plate number of the car to rent: ");
                    String plateToRent = scanner.nextLine();
                    Car carToRent = null;
                    for (Car car : carRaceManagement.getCars()) {
                        if (car.getPlateNumber().equals(plateToRent)) {
                            carToRent = car;
                            break;
                        }
                    }
                    if (carToRent != null) {
                        System.out.print("Enter renter email: ");
                        String renterEmail = scanner.nextLine();
                        Renter rentingRenter = null;
                        for (Renter renter : carRaceManagement.getRenters()) {
                            if (renter.getEmail().equals(renterEmail)) {
                                rentingRenter = renter;
                                break;
                            }
                        }
                        if (rentingRenter != null) {
                        	System.out.print("Enter distance (in kilometers): ");
                            double distance = scanner.nextDouble();
                            char isInsurable = ' ';
                            if(carToRent.isInsurable()) {
                            	 System.out.print("Would you like to add insurance? (Y/N): ");
                                  isInsurable = scanner.next().charAt(0);
                            }
                            else
                            {
                            	 System.out.println("This car is not insurable. Renting without insurance.");
                            	 isInsurable = 'N';
                            }
                            carRaceManagement.rentCar(carToRent, rentingRenter, distance, isInsurable == 'Y' || isInsurable == 'y');
                        } else {
                            System.out.println("Renter not found with the provided email.");
                        }
                    } else {
                        System.out.println("Car not found with the provided plate number.");
                    }
                    break;
                case 8:
                    // Display rental details
                    carRaceManagement.displayRentalDetails();
                    break;
                case 9:
                    // Calculate total rental cost
                    carRaceManagement.DisplayTotalRentalCost();
                    break;
                case 10:
                    // Return a car
                    System.out.print("Enter the plate number of the car to return: ");
                    String plateToReturn = scanner.nextLine();
                    Car carToReturn = null;
                    for (Car car : carRaceManagement.getCars()) {
                        if (car.getPlateNumber().equals(plateToReturn)) {
                            carToReturn = car;
                            break;
                        }
                    }
                    if (carToReturn != null) {
                        
                    	
                        carRaceManagement.returnCar(carToReturn);
                    } else {
                        System.out.println("Car not found with the provided plate number.");
                    }
                    break;
                case 11:
                    // Exit
                    System.out.println("Exiting...");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please enter a number between 1 and 11.");
            }
            System.out.println("");
            System.out.println("----------------------------------------");
        }

	}

}
