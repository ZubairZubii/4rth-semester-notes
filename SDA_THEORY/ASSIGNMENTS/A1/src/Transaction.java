
public class Transaction {

	 private Car car;
	    private Renter renter;
	    private double totalCost;

	    public Transaction(Car car, Renter renter, double totalCost) {
	        this.car = car;
	        this.renter = renter;
	        this.totalCost = totalCost;
	    }

	    public Car getCar() {
	        return car;
	    }

	    public Renter getRenter() {
	        return renter;
	    }

	    public double getTotalCost() {
	        return totalCost;
	    }

	    
}
