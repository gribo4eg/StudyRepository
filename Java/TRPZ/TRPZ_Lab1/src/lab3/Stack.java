package lab3;

import lab.Product;

public class Stack {
    private Product stack[];
    private int maxSize;
    private int curSize;
    private int head;

    public Stack(int capacity) {
        maxSize = capacity;
        curSize = 0;
        stack = new Product[maxSize];
        head = -1;
    }

    public boolean isEmpty() {
        return curSize == 0;
    }

    public boolean isFull() {
        return curSize == maxSize;
    }

    public void push(Product value) {
        if (isFull()){
            System.out.printf("The stack is full, cannot add '%s' element!\n", value);
        }
        else {
            stack[++head] = value;
            curSize++;
        }
    }

    public Product pop() {
        if (isEmpty()) {
            System.out.println("Nothing to pop, the stack is empty!");
            return null;
        }
        else {
            Product del = stack[head--];
            // stack[head] = "";
            curSize--;
            return del;
        }
    }

    public void output(){
        int i;
        if (isEmpty()) {
            System.out.printf("The stack is empty, nothing to display!");
        }
        else {
            System.out.println("Stack: ");
            for (i = head; i >= 0; i--) {
                stack[i].printProduct();
            }
        }
        System.out.println("\n");
    }
}
