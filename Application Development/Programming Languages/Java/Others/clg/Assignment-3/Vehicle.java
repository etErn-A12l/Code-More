class Vehicle {
    protected String regnNumber;
    protected int speed;
    protected String color;
    protected String ownerName;

    public void showData() {
        System.out.println("This is a vehicle class");
        System.out.println("Regn Number: " + regnNumber);
        System.out.println("Speed: " + speed);
        System.out.println("Color: " + color);
        System.out.println("Owner Name: " + ownerName);
    }
}

class Bus extends Vehicle {
    private int routeNumber;

    public void showData() {
        super.showData();
        System.out.println("Bus Details: ");
        System.out.println("Route Number: " + routeNumber);
    }
}

class Car extends Vehicle {
    private String manufacturerName;

    public void showData() {
        super.showData();
        System.out.println("Car Details: ");
        System.out.println("Manufacturer Name: " + manufacturerName);
    }
}
