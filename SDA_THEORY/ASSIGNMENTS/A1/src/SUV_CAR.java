
// Represents an SUV car, extending the Car abstract class.
 
public class SUV_CAR extends Car {
    
    // Constants for insurance and damage percentage
    private final double insurancePercentage = 0.1;
    private final double damagePercentage = 0.08;

    // Constructor
    public SUV_CAR(int carID, String brand, String model, int year, double rentalFee, String plateNumber) {
        super(carID, brand, model, year, rentalFee, plateNumber);
    }

    // Method to calculate insurance cost for an SUV car
    public double calculateInsuranceCost() {
        return insurancePercentage * getRentalFee(); 
    }

    // Method to calculate base rent for an SUV car with additional distance travel cost
    public double calculateBaseRent(double distance) {
        double distance_travel_cost = distance * distance_cost_factor; 
        return getRentalFee() + distance_travel_cost;
    }

    // Method to calculate damage cost for an SUV car based on insurance status and total rent
    public double calculateDamageCost(boolean isInsured, double totalRent) {
        if (isInsured) {
            double damage = damagePercentage * (totalRent - calculateInsuranceCost());
            return Math.max(damage, 100); // Ensure minimum damage cost
        } else {
            return damagePercentage * getRentalFee(); // Calculate damage cost without insurance
        }
    }

    // Method to check if an SUV car is isInsurable
    boolean isInsurable() {
        return true; 
    }
}
