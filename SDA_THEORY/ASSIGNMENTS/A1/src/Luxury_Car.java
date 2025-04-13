
// Represents a luxury car, extending the Car abstract class.
 
public class Luxury_Car extends Car {
    
    // Constants for insurance and damage percentage
    private final double insurancePercentage = 0.15;
    private final double damagePercentage = 0.1;
    
    // Constant for luxury tax
    private final double luxuryTax = 0.1;
    
    // Constructor
    public Luxury_Car(int carID, String brand, String model, int year, double rentalFee, String plateNumber) {
        super(carID, brand, model, year, rentalFee, plateNumber);
    }

    // Method to calculate insurance cost for a luxury car
    public double calculateInsuranceCost() {
        return insurancePercentage * getRentalFee(); 
    }
    
    // Method to calculate base rent for a luxury car with additional luxury tax and distance travel cost
    public double calculateBaseRent(double distance) {
        double distance_travel_cost = distance * distance_cost_factor; 
        return getRentalFee() + distance_travel_cost + luxuryTax;
    }

    // Method to calculate damage cost for a luxury car based on insurance status and total cost
    public double calculateDamageCost(boolean isInsured, double totalCost) {
        if (isInsured) {
            return Math.max(damagePercentage * (totalCost - calculateInsuranceCost()), 100); // Minimum damage cost
        } else {
            return damagePercentage * totalCost; // Calculate damage cost without insurance
        }
    }
    
    // Method to check if a luxury car is isInsurable
    boolean isInsurable() {
        return true; 
    }
}
