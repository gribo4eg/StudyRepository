package lab1;

public class Product {

    private String name;
    private double cost;

    public Product(String name, double cost) {
        this.name = name;
        this.cost = cost;
    }


    public String getName() {
        return name;
    }

    public double getCost() {
        return cost;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    public void printProduct(){
        System.out.println(String.format("Product: %s, cost: %.2f", name, cost));
    }
}
