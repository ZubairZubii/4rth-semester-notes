import static org.junit.Assert.*;

import org.junit.Test;

/**
 * Test cases for the Car_Rental_Management class.
 */
public class TestCases {

    // Instance of Car_Rental_Management for testing
    private Car_Rental_Management carRentalManagement = new Car_Rental_Management();
    
    // Test case to verify the addition of a Compact Car
    @Test
    public void testAddCar() {
        Compact_Car cc = new Compact_Car(1, "Toyota", "Corolla", 2022, 50.0, "ABC123");
        carRentalManagement.addCar(cc);
        assertTrue(carRentalManagement.getCars().contains(cc));
    }
  
    // Test case to verify the addition of a Renter
    @Test
    public void testAddRenter() {
        Renter newRenter = new Frequent_Renter(1, "John Doe", "john@example.com", "1234567890", "123 Street, City");
        carRentalManagement.addRenter(newRenter);
        assertTrue(carRentalManagement.getRenters().contains(newRenter));
    }

    // Test case to verify the insurable status of a Compact Car
    @Test
    public void testCompactCarInsurableStatus() {
        Car compactCar = new Compact_Car(1, "Toyota", "Corolla", 2022, 50.0, "ABC123");
        assertFalse(compactCar.isInsurable());
    }

    // Test case to verify the insurable status of an SUV Car
    @Test
    public void testSUVCarInsurableStatus() {
        Car suvCar = new SUV_CAR(2, "Ford", "Explorer", 2022, 70.0, "XYZ456");
        assertTrue(suvCar.isInsurable());
    }

    // Test case to calculate the rental fee for an SUV Car
    @Test
    public void testCalculateRentalFee() {
        double base_rent = 50.0;
        Car suvCar = new SUV_CAR(1, "Toyota", "Corolla", 2022, base_rent, "ABC123");
        double distance = 20.0;
     
        double expectedRentalFee = (distance * 0.1) + base_rent ;
        assertEquals(expectedRentalFee, suvCar.calculateBaseRent(distance), 0.001);
    }

    // Test case to verify the removal of a Car
    @Test
    public void testRemoveCar() {
        Car car = new SUV_CAR(1, "Toyota", "Corolla", 2022, 50.0, "ABC123");
        carRentalManagement.addCar(car);
        carRentalManagement.removeCar(car);
        assertFalse(carRentalManagement.getCars().contains(car));
    }

    // Test case to verify the removal of a Renter
    @Test
    public void testRemoveRenter() {
        Renter renter = new Cooperate_Renter(1, "John Doe", "john@example.com", "1234567890", "123 Street, City");
        carRentalManagement.addRenter(renter);
        carRentalManagement.removeRenter(renter);
        assertFalse(carRentalManagement.getRenters().contains(renter));
    }

    // Test case to verify the renting of a Car
    @Test
    public void testRentCar() {
        Car car = new SUV_CAR(1, "Toyota", "Corolla", 2022, 50.0, "ABC123");
        Renter renter = new Cooperate_Renter(1, "John Doe", "john@example.com", "1234567890", "123 Street, City");
        carRentalManagement.addCar(car);
        carRentalManagement.addRenter(renter);
        carRentalManagement.rentCar(car, renter, 50.0, true);
        assertTrue(car.isRentalStatus());
    }

    // Test case to verify the return of a Car
    @Test
    public void testReturnCar() {
        Car car = new SUV_CAR(1, "Toyota", "Corolla", 2022, 50.0, "ABC123");
        Renter renter = new Cooperate_Renter(1, "John Doe", "john@example.com", "1234567890", "123 Street, City");
        carRentalManagement.addCar(car);
        carRentalManagement.addRenter(renter);
        carRentalManagement.rentCar(car, renter, 50.0, true);
        carRentalManagement.returnCar(car);
        assertFalse(car.isRentalStatus());
    }

    // Test case to verify the total rental cost calculation
    @Test
    public void testTotalRentalCost() {
        Car car = new SUV_CAR(1, "Toyota", "Corolla", 2022, 50.0, "ABC123");
        Renter renter = new Frequent_Renter(1, "John Doe", "john@example.com", "1234567890", "123 Street, City");
        carRentalManagement.addCar(car);
        carRentalManagement.addRenter(renter);
        carRentalManagement.rentCar(car, renter, 50.0, true);
        
        double baseRent = car.calculateBaseRent(50.0);
        double insuranceCost = car.calculateInsuranceCost();
        double totalCost = baseRent + insuranceCost;
        double discount = renter.calculateDiscounted(totalCost);
        double expectedTotalCost = totalCost - discount;

        assertEquals(expectedTotalCost, carRentalManagement.getTransaction().get(0).getTotalCost(), 0.001);
    }

    // Test case to verify the calculation of damage cost for different types of cars
    @Test
    public void testDamageCost() {
        // Create a compact car
        Car compactCar = new Compact_Car(1, "Toyota", "Corolla", 2022, 50.0, "ABC123");
        Renter renter = new Frequent_Renter(1, "John Doe", "john@example.com", "1234567890", "123 Street, City");

        carRentalManagement.addCar(compactCar);
        carRentalManagement.addRenter(renter);

        carRentalManagement.rentCar(compactCar, renter, 50.0, false);
        double totalRentalCost = compactCar.calculateBaseRent(50.0) + compactCar.calculateInsuranceCost();
        double damageCostCompact = totalRentalCost * 0.05;

        // Verify damage cost for compact car
        assertEquals(damageCostCompact, compactCar.calculateDamageCost(false, totalRentalCost), 0.001);
        
        
        // Create an SUV car
        Car suvCar = new SUV_CAR(2, "Honda", "CRV", 2022, 60.0, "XYZ456");

        carRentalManagement.addCar(suvCar);

        carRentalManagement.rentCar(suvCar, renter, 50.0, true);
        totalRentalCost = suvCar.calculateBaseRent(50.0) + suvCar.calculateInsuranceCost();
        double damageCostSUV = Math.max(0.08 * (totalRentalCost - suvCar.calculateInsuranceCost()), 100);

        // Verify damage cost for SUV car
        assertEquals(damageCostSUV, suvCar.calculateDamageCost(true, totalRentalCost), 0.001);
    }
}
