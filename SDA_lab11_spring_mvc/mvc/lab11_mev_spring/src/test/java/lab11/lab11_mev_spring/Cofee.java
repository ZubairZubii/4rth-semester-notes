package lab11.lab11_mev_spring;

public class Cofee {
    private String type;
    private String size;
    private double price;

   
    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }
}


class Espresso extends Cofee {
    public Espresso() {
        setType("espresso");
    }
}

 class Latte extends Cofee {
    public Latte() {
        setType("latte");
    }
}


