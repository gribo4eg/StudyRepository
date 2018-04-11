package lab;

import com.sun.org.apache.xpath.internal.operations.Or;

import javax.xml.crypto.Data;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class Menu {

    private static ArrayList<String> managerMenu = new ArrayList<>(Arrays.asList(
            "1. Get Closed Orders",
            "2. Get All Orders",
            "3. Get Staff List",
            "4. Add new Person",
            "5. Remove Person"
    ));

    private static ArrayList<String> waiterMenu = new ArrayList<>(Arrays.asList(
            "1. Get Closed Orders",
            "2. Get All Orders",
            "3. Add new Order",
            "4. Close Order"
    ));

    public static void showMenu(Staff person) {
        switch (person.getRole()) {
            case MANAGER:
                for (String menuPart : managerMenu) {
                    System.out.print(menuPart);
                }
                break;
            case WAITER:
                for (String menuPart : waiterMenu) {
                    System.out.print(menuPart);
                }
                break;
            default:
                System.out.print("Something goes wrong");
        }
    }

    public static void chosenFunction(Database db, Staff person, int chosen) {
        switch (person.getRole()) {
            case MANAGER:
                managerFunctions(db, chosen);
                break;
            case WAITER:
                System.out.print("Waiter function");
                break;
            default:
                System.out.print("Something goes wrong");
        }
    }

    private static void managerFunctions(Database db, int chosen) {
        List<Order> orders;
        switch (chosen) {
            case 1:
                orders = db.getClosedOrder();
                for (Order order : orders) {
                    order.printOrder();
                }
                break;
            case 2:
                orders = db.getOrders();
                for (Order order : orders) {
                    order.printOrder();
                }
                break;
            case 3:break;
            case 4:break;
            case 5:break;
        }
    }
}
