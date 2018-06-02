package lab1;

public class Staff {

    private String name;
    private StaffRole role;

    public Staff(String name, StaffRole role) {
        this.name = name;
        this.role = role;
    }


    public String getName() {
        return name;
    }

    public StaffRole getRole() {
        return role;
    }
}
