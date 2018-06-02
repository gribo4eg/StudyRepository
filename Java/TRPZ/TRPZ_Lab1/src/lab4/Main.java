package lab4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

class Order {
    private String name;
    private double cost;

    public Order(String name, double cost){
        this.name = name;
        this.cost = cost;
    }

    @Override
    public String toString() {
        return "Order: "+this.name+"; Cost: "+this.cost;
    }

    public Order updateOrder(String newName, double newCost){
        this.name = newName;
        this.cost = newCost;
        return this;
    }
}

public class Main {

    public static void main(String argv[]){
        System.out.println("Orders menu:");
        System.out.println("1. Show orders");
        System.out.println("2. Create order");
        System.out.println("3. Edit order");
        System.out.println("4. Close order");

        LinkedList orders = new LinkedList();
        orders.add(new Order("Order1", 5.2));
        orders.add(new Order("Order2", 4.4));
        orders.add(new Order("Order3", 5.5));
        orders.add(new Order("Order4", 10));

        BufferedReader bd = new BufferedReader(new InputStreamReader(System.in));
        while (true){
            String chose;
            try {
                chose = bd.readLine();
            } catch (IOException e) {
                System.out.println("BYE BYE");
                break;
            }
            if (chose.equals("exit")) break;
            switch (chose){
                case "1":
                    for (Object order :
                            orders) {
                        System.out.println(order);
                    }
                    break;
                case "2":
                    System.out.println("Order name:");
                    String name;
                    try {
                        name = bd.readLine();
                    } catch (IOException e){
                        break;
                    }
                    System.out.println("Order cost:");
                    double cost;
                    try {
                        cost = Double.parseDouble(bd.readLine());
                    } catch (IOException e){
                        break;
                    }
                    orders.add(new Order(name, cost));
                case "3":
                    break;
                case "4":
                    int num;
                    try {
                        num = Integer.parseInt(bd.readLine());
                    } catch (IOException e){
                        break;
                    }
                    orders.remove(num);
                default:
                    System.out.println("Break command");
            }
        }
    }
}
