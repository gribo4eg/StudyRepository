package lab1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) {
        Staff person = new Staff("Michael", StaffRole.MANAGER);
        Database db = new Database();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Menu.showMenu(person);
        while (true) {
            String chose;
            try {
                chose = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
                break;
            }
            if (chose.equals("exit")) break;
            Menu.chosenFunction(db, person, Integer.parseInt(chose));
        }
    }
}
