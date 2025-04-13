
// Abstract class representing a generic car.
abstract class Car {
    
    // Attributes
    private int CarID;
    private String Brand;
    private String Model;
    private int year;
    private boolean Rental_Status;
    private double Rental_Fee;
    private String Plate_Number;

    // Constant for distance cost factor
    public static final double distance_cost_factor = 0.1;
    
    // Constructor
    public Car(int carID, String brand, String model, int year, double rentalFee, String plateNumber) {
        this.CarID = carID;
        this.Brand = brand;
        this.Model = model;
        this.year = year;
        this.Rental_Fee = rentalFee;
        this.Plate_Number = plateNumber;
        this.Rental_Status = false; 
    }
    
    // Getters and setters
    public int getCarID() {
        return CarID;
    }

    public void setCarID(int carID) {
        CarID = carID;
    }

    public String getBrand() {
        return Brand;
    }

    public void setBrand(String brand) {
        Brand = brand;
    }

    public String getModel() {
        return Model;
    }

    public void setModel(String model) {
        Model = model;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public boolean isRentalStatus() {
        return Rental_Status;
    }

    public void setRentalStatus(boolean rentalStatus) {
        Rental_Status = rentalStatus;
    }

    public double getRentalFee() {
        return Rental_Fee;
    }

    public void setRentalFee(double rentalFee) {
        Rental_Fee = rentalFee;
    }

    public String getPlateNumber() {
        return Plate_Number;
    }

    public void setPlateNumber(String plateNumber) {
        Plate_Number = plateNumber;
    }
    
    // Abstract methods
    abstract double calculateBaseRent(double distance);
    abstract double calculateInsuranceCost();
    abstract double calculateDamageCost(boolean isInsured, double baseRent);
    abstract boolean isInsurable();
    
}
