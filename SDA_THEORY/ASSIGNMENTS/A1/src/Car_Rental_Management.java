
import java.util.ArrayList;
import java.util.List;

//Manages the rental operations for cars and renters.
public class Car_Rental_Management {

	// Lists to store cars, renters, and transactions
	private List<Car> cars;
    private List<Renter> renters;
    private List<Transaction> transactions;

 // Constructor initializes the lists
    public Car_Rental_Management() {
        cars = new ArrayList<>();
        renters = new ArrayList<>();
        transactions = new ArrayList<>();
    }
    
    
    public void addCar(Car car) {
        cars.add(car);
        System.out.println("Car Add successfully.");
    }
    
    // Method to retrieve the list of cars
    public List<Car> getCars() {
        return cars;
    }

 // Method to retrieve the list of transactions
    public List<Transaction> getTransaction() {
        return transactions;
    }
    
    // Method to remove a car from the list of cars
    public void removeCar(Car car) {
        if (!car.isRentalStatus()) {
            cars.remove(car);
            System.out.println("Car removed successfully.");
        } else {
            System.out.println("Cannot remove rented car.");
        }
    }
    
    public void display_All_AvailableCars() {
        System.out.println("Available Cars:");
        for (Car car : cars) {
            if (!car.isRentalStatus()) {
                System.out.println("----------------------------------------");
                System.out.println("Car ID: " + car.getCarID());
                System.out.println("Brand: " + car.getBrand());
                System.out.println("Model: " + car.getModel());
                System.out.println("Year: " + car.getYear());
                System.out.println("Rental Fee: $" + car.getRentalFee());
                System.out.println("Plate Number: " + car.getPlateNumber());
                if (car instanceof Compact_Car) {
                    System.out.println("Type: Compact Car");
                } else if (car instanceof SUV_CAR) {
                    System.out.println("Type: SUV Car");
                } else if (car instanceof Luxury_Car) {
                    System.out.println("Type: Luxury Car");
                }
              
                System.out.println("----------------------------------------");
            }
        }
    }

 // Method to add a renter to the list of renters
    public void addRenter(Renter renter) {
        renters.add(renter);
        System.out.println("Renter Add successfully.");
    }

    // Method to retrieve the list of renters
    public List<Renter> getRenters() {
        return renters;
    }
    
 // Method to remove a renter from the list of renters
    public void removeRenter(Renter renter) {
        renters.remove(renter);
        System.out.println("Renter removed successfully.");
    }

 // Method to display details of all renters    
    public void displayRenters() {
        System.out.println("Renter Details:");
        for (Renter renter : renters) {
            System.out.println("----------------------------------------");
        	 System.out.println("Renter ID: " + renter.getRenterID());
             System.out.println("Name: " + renter.getName());
             System.out.println("Email: " + renter.getEmail());
             System.out.println("Phone Number: " + renter.getPhoneNumber());
             System.out.println("Address: " + renter.getAddress());
             System.out.println("----------------------------------------");
        }
    }

 // Method to rent a car to a renter
    public void rentCar(Car car, Renter renter, double distance, boolean isInsured) {
        if (car.isRentalStatus()) {
            System.out.println("Sorry, the car is already rented.");
            return;
        }

        double baseRent = car.calculateBaseRent(distance);
        double totalCost = baseRent;

        if (isInsured) {
            totalCost += car.calculateInsuranceCost();
        }

        double discountRate = renter.calculateDiscounted(totalCost);
        totalCost -= discountRate;

        // Format percentages to two significant digits
        String baseRentFormatted = String.format("%.2f", baseRent);
        String insuranceCostFormatted = String.format("%.2f", car.calculateInsuranceCost());
        String discountRateFormatted = String.format("%.2f", discountRate);
        String totalCostFormatted = String.format("%.2f" ,totalCost );
        		
        
        Transaction transaction = new Transaction(car, renter, totalCost);
        transactions.add(transaction);
        renter.rentCar(car);
        car.setRentalStatus(true);
        System.out.println("----------------------------------------");
        System.out.println("Car rented successfully.");
        System.out.println("Rental Details:");
        System.out.println("Renter: " + renter.getName());
        System.out.println("Car: " + car.getBrand() + " " + car.getModel());
        System.out.println("Base Rent: $" + baseRentFormatted);
        if (isInsured) {
            System.out.println("Insurance Cost: $" + insuranceCostFormatted);
        }
        System.out.println("Discount Applied: $" + discountRateFormatted);
        System.out.println("Total Cost: $" + totalCostFormatted);
        System.out.println("----------------------------------------");
    }

 // Method to display details of all transactions
    public void displayRentalDetails() {
        System.out.println("Rental Details:");
        for (Transaction transaction : transactions) {
            Renter renter = transaction.getRenter();
            Car car = transaction.getCar();
            System.out.println("----------------------------------------");
            System.out.println("Renter: " + renter.getName());
            System.out.println("  Email: " + renter.getEmail());
            System.out.println("  Phone Number: " + renter.getPhoneNumber());
            System.out.println("  Address: " + renter.getAddress());
            
            System.out.println("Car:");
            System.out.println("  Brand: " + car.getBrand());
            System.out.println("  Model: " + car.getModel());
            System.out.println("  Year: " + car.getYear());
            System.out.println("  Rental Fee: $" + car.getRentalFee());
            System.out.println("  Plate Number: " + car.getPlateNumber());
            
            System.out.println("Transaction Details:");
            String totalCostFormatted = String.format("%.2f" , transaction.getTotalCost() );
            System.out.println("  Total Cost: $" + totalCostFormatted);
            
            System.out.println("----------------------------------------");
        }
    }


 // Method to calculate and display the total rental cost
    public void DisplayTotalRentalCost() {
        double totalCost = 0;
        for (Transaction transaction : transactions) {
            totalCost += transaction.getTotalCost();
        }
        String totalCostFormatted = String.format("%.2f" , totalCost );
        System.out.println("----------------------------------------");
        System.out.println("Total Rental Cost: $" + totalCostFormatted);
        System.out.println("----------------------------------------");
    }

    // Helper method to find the renter associated with a car
    private Renter findRenter(Car car) {
        for (Renter renter : renters) {
            if (renter.getRentedCars().contains(car)) {
                return renter;
            }
        }
        return null;
    }
    
    
    // Helper method to find the transaction associated with a car
    private Transaction findTransaction(Car car) {
        for (Transaction transaction : transactions) {
            if (transaction.getCar().equals(car)) {
                return transaction;
            }
        }
        return null;
    }
    
    
    // Method to return a rented car
    public void returnCar(Car car) {
        car.setRentalStatus(false);
        Renter renter = findRenter(car);
        if (renter != null) {
            renter.returnCar(car);
            Transaction transaction = findTransaction(car);
            if (transaction != null) {
                boolean isInsured = car.isInsurable();
                double totalCost = transaction.getTotalCost();
                double damageCost = 0.0;

                // Check car type and calculate damage cost accordingly
                if (isInsured) {
                    damageCost = car.calculateDamageCost(isInsured, totalCost);
                } else {
                    damageCost = car.calculateDamageCost(isInsured, totalCost);
                }
                System.out.println("----------------------------------------");
                // Display additional details
                System.out.println("Renter Name: " + renter.getName());
                System.out.println("Car Brand: " + car.getBrand());
                System.out.println("Car Model: " + car.getModel());
                String damageCostFormatted = String.format("%.2f" ,damageCost );
                String totalCostFormatted = String.format("%.2f" ,totalCost );
                System.out.println("Damage cost: $" + damageCostFormatted);
                System.out.println("Total cost: $" + totalCostFormatted);
                System.out.println("----------------------------------------");

                transactions.remove(transaction);
            }
        }
    }




}



