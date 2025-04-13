
public class Cooperate_Renter extends Renter{

	 private final double DISCOUNT_RATE ;
	 
    public Cooperate_Renter(int renterID, String name, String email, String phoneNumber, String address) {
        super(renterID, name, email, phoneNumber, address);
        this.DISCOUNT_RATE = 0.2;
    }

    @Override
    public double calculateDiscounted(double rentalFee) {
        return DISCOUNT_RATE * rentalFee; 
    }
}


