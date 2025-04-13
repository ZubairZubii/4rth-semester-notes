import java.util.ArrayList;
import java.util.List;


 // Abstract class representing a renter.
 
abstract public class Renter {

    // Attributes
    private int RenterID;
    private String Name;
    private String Email;
    private List<Car> RentedCars;
    private double TotalRentalFee;
    private String PhoneNumber;
    private String Address;

    // Constructor
    public Renter(int RenterID, String Name, String Email, String PhoneNumber, String Address) {
        this.RenterID = RenterID;
        this.Name = Name;
        this.Email = Email;
        this.RentedCars = new ArrayList<>();
        this.PhoneNumber = PhoneNumber;
        this.Address = Address;
        this.TotalRentalFee = 0.0;
    }

    // Abstract method to calculate discounted rental fee
    public abstract double calculateDiscounted(double rentalFee);

    // Method to calculate total rental fee
    public void calTotalRentalFee() {
        for (Car car : RentedCars) {
            TotalRentalFee += car.getRentalFee();
        }
    }
    
    // Method to rent a car
    public void rentCar(Car car) {
        RentedCars.add(car);
    }

    // Method to return a car
    public void returnCar(Car car) {
        RentedCars.remove(car);
    }

    // Getters and setters for the attributes
    public int getRenterID() {
        return RenterID;
    }

    public void setRenterID(int renterID) {
        RenterID = renterID;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public String getEmail() {
        return Email;
    }

    public void setEmail(String email) {
        Email = email;
    }

    public List<Car> getRentedCars() {
        return RentedCars;
    }

    public void setRentedCars(List<Car> rentedCars) {
        RentedCars = rentedCars;
    }

    public double getTotalRentalFee() {
        return TotalRentalFee;
    }

    public void setTotalRentalFee(double totalRentalFee) {
        TotalRentalFee = totalRentalFee;
    }

    public String getPhoneNumber() {
        return PhoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        PhoneNumber = phoneNumber;
    }

    public String getAddress() {
        return Address;
    }

    public void setAddress(String address) {
        Address = address;
    }
}
