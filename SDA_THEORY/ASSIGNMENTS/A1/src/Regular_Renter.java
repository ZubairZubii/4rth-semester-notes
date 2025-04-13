
 //Represents a regular renter, extending the Renter abstract class.
 
public class Regular_Renter extends Renter {

    // Constructor
    public Regular_Renter(int renterID, String name, String email, String phoneNumber, String address) {
        super(renterID, name, email, phoneNumber, address);
    }

    // Method to calculate discounted rental fee for a regular renter (no discount)
    public double calculateDiscounted(double rentalFee) {
        return rentalFee; 
    }
}
