
public class Frequent_Renter  extends Renter{

	  private final double DISCOUNT_RATE ;

	    public Frequent_Renter(int renterID, String name, String email, String phoneNumber, String address) {
	        super(renterID, name, email, phoneNumber, address);
	        this.DISCOUNT_RATE= 0.1;
	    }

	    @Override
	    public double calculateDiscounted(double rentalFee) {
	    	System.out.print("FRERENTER");
	        return DISCOUNT_RATE * rentalFee; // Frequent renters get discounted rates
	    }
	    
}


