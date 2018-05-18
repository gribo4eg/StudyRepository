package lab3;

import lab.Product;

import java.util.Random;

public class Main {

    public static void main(String[] argv){
        start_stack();
        start_queue();
    }

    private static double getRand (double min, double max, Random random){
        return min + (max - min) * random.nextDouble();
    }

    private static void start_stack(){
        System.out.println("Stack started:\n");

        double min = 0.5, max = 99.99;
        Random random = new Random();
        Stack s = new Stack(5);
        Product[] products = new Product[] {
                new Product("Product 1", getRand(min,max,random)),
                new Product("Product 2", getRand(min,max,random)),
                new Product("Product 3", getRand(min,max,random)),
                new Product("Product 4", getRand(min,max,random)),
                new Product("Product 5", getRand(min,max,random)),
        };
        for(Product p: products) {
            System.out.println("Product in stack: " + p.getName());
            s.push(p);
        }

        System.out.println();
        s.output();
        while (!s.isEmpty()) {
            System.out.println("Product poped from stack: " + s.pop().getName());
        }

        System.out.println("Stack ended\n\n");
    }

    private static void start_queue(){
        System.out.println("Queue started:\n");

        double min = 0.5, max = 99.99;
        Random random = new Random();
        Queue s = new Queue(5);
        Product[] products = new Product[] {
                new Product("Product 1", getRand(min,max,random)),
                new Product("Product 2", getRand(min,max,random)),
                new Product("Product 3", getRand(min,max,random)),
                new Product("Product 4", getRand(min,max,random)),
                new Product("Product 5", getRand(min,max,random)),
        };
        for(Product p: products) {
            System.out.println("Product in queue: " + p.getName());
            s.enqueue(p);
        }

        System.out.println();
        s.output();
        while (!s.isEmpty()) {
            System.out.println("Product removed from queue: " + s.dequeue().getName());
        }

        System.out.println("Queue ended\n\n");
    }

}
