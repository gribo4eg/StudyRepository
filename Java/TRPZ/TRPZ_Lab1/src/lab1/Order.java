package lab1;

import java.util.ArrayList;
import java.util.List;

public class Order {

    private long id;
    private OrderStatus status;
    private List<Product> products = new ArrayList<>();

    public Order (long id, List<Product> products) {
        this.id = id;
        this.products.addAll(products);
        this.status = OrderStatus.OPEN;
    }

    public long getId() {
        return id;
    }

    public List<Product> getProducts() {
        return products;
    }

    public void addProduct(Product product) {
        products.add(product);
    }

    public double getTotalCost() {
        double cost = 0.0;
        for (Product product:products) {
            cost += product.getCost();
        }
        return cost;
    }

    public OrderStatus getStatus() {
        return status;
    }

    public void setStatus(OrderStatus status) {
        this.status = status;
    }

    public void printOrder() {
        System.out.print(String.format("Order: id = %d ", id));
        System.out.print("\tProducts:");
        for (Product product : products) {
            System.out.print(String.format("\t\t%s", product.getName()));
        }
        System.out.print("\tStatus = "+status);
    }
}
