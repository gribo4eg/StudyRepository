package lab2;

import lab.*;

import java.util.Random;


public class Main {

    private static double getRand (double min, double max, Random random){
        return min + (max - min) * random.nextDouble();
    }

    static void merge(Product arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        Product L[] = new Product [n1];
        Product R[] = new Product [n2];

        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];

        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i].getCost() <= R[j].getCost())
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    static void sort(Product arr[], int l, int r)
    {
        if (l < r)
        {
            int m = (l+r)/2;
            sort(arr, l, m);
            sort(arr , m+1, r);

            merge(arr, l, m, r);
        }
    }

    public static void main(String[] argv){
        Random random = new Random();
        double min = 0.99, max = 99.99;
        Product[] products = new Product[]{
                new Product("Product 1", getRand(min,max,random)),
                new Product("Product 2", getRand(min,max,random)),
                new Product("Product 3", getRand(min,max,random)),
                new Product("Product 4", getRand(min,max,random)),
                new Product("Product 5", getRand(min,max,random)),
                new Product("Product 6", getRand(min,max,random)),
                new Product("Product 7", getRand(min,max,random)),
                new Product("Product 8", getRand(min,max,random)),
                new Product("Product 9", getRand(min,max,random)),
                new Product("Product 10", getRand(min,max,random)),
                new Product("Product 11", getRand(min,max,random))
        };

        System.out.println("Before:");
        for (Product prod :
                products) {
            prod.printProduct();
        }
        sort(products, 0, products.length - 1);
        System.out.println("\nAfter:");
        for (Product prod :
                products) {
            prod.printProduct();
        }
    }



}
