package lab;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;

public class Database {
    private List<Staff> staff = new ArrayList<>();
    private List<Order> orders = new ArrayList<>();
    private List<Product> products = new ArrayList<>();

    public Database () {}

    public void addPerson(Staff person) {
        staff.add(person);
    }

    public boolean removePerson(Staff person) {
        return staff.remove(person);
    }

    public List<Staff> getStaff() {
        return staff;
    }

    public long addOrder(List<String> wishedProducts) {
        List<Product> toOrder = new ArrayList<>();
        for (String product : wishedProducts) {
            if (this.haveProduct(product)) {
                toOrder.add(getProduct(product));
            } else {
                System.out.print("No such product: " + product);
            }
        }
        if (toOrder.size() != 0) {
            long id = getId();
            this.orders.add(new Order(id, toOrder));
            return id;
        } else {
            return -1;
        }
    }

    public boolean closeOrder(long id) {
        Order order = getOrder(id);
        if (order != null) {
            order.setStatus(OrderStatus.CLOSED);
            return true;
        }
        return false;
    }

    public List<Order> getClosedOrder() {
        List<Order> closed = new ArrayList<>();
        for (Order order : orders) {
            if (order.getStatus() == OrderStatus.CLOSED)
                closed.add(order);
        }
        return closed;
    }

    public List<Order> getOrders() {
        return orders;
    }

    private boolean haveProduct(String productName) {
        for (Product product : products) {
            if (product.getName().equals(productName)) {
                return true;
            }
        }
        return false;
    }

    private Product getProduct(String productName) {
        for (Product product : products) {
            if (product.getName().equals(productName)) {
                return product;
            }
        }
        return null;
    }

    private long getId() {
        Order maxIdOrder = this.orders
                .stream()
                .max(Comparator.comparing(Order::getId))
                .orElseThrow(NoSuchElementException::new);
        return maxIdOrder.getId();
    }

    private Order getOrder(long id) {
        for (Order order : this.orders) {
            if (id == order.getId())
                return order;
        }
        return null;
    }
}
