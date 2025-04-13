package lab11.lab11_mev_spring;
import org.springframework.beans.factory.annotation.Autowired;

public class Coffee_shop {
    private Cofee coffee;


    @Autowired
    public  void setCoffee(Cofee coffee) {
        this.coffee = coffee;
    }

    public void serveCoffee() {
        System.out.println("Coffee served:");
        System.out.println("Type: " + coffee.getType());
        System.out.println("Size: " + coffee.getSize());
        System.out.println("Price: $" + coffee.getPrice());
    }
}
