
// Represents a compact car, extending the Car abstract class.
 
public class Compact_Car extends Car {
    
    // Constant for damage percentage
    private final double damagePercentage = 0.05;
    
    // Constructor
    public Compact_Car(int carID, String brand, String model, int year, double rentalFee, String plateNumber) {
        super(carID, brand, model, year, rentalFee, plateNumber);
    }

    // Method to calculate base rent for a compact car with additional distance travel cost
    public double calculateBaseRent(double distance) {
        double distance_travel_cost = distance * distance_cost_factor;
        return getRentalFee() + distance_travel_cost; 
    }

    // Method to calculate insurance cost for a compact car (always returns 0 as compact cars are not insurable)
    public double calculateInsuranceCost() {
        return 0; 
    }

    // Method to calculate damage cost for a compact car based on insurance status and total rent
    public double calculateDamageCost(boolean isInsured, double totalRent) {
        if (isInsured) {
            return 0; 
        } else {
            return totalRent * damagePercentage; 
        }
    }
    
    // Method to check if a compact car is isInsurable (always returns false)
    boolean isInsurable() {
        return false;
    }

}
