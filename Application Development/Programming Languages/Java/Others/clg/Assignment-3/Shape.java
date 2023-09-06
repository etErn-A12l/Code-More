
abstract class Shape {
    public abstract void calculateArea();

    public abstract void calculatePerimeter();
}

class Rectangle extends Shape {

    double height, width;

    public Rectangle(double height, double width) {
        this.height = height;
        this.width = width;
    }

    public void calculateArea() {
        System.out.println("The Area of the Rectangle: " + height * width);
    }

    public void calculatePerimeter() {
        System.out.println("The Perimeter of the Rectangle: " + 2 * (height + width));
    }
}

class Triangle extends Shape {
    double side, height;

    public Triangle(double side, double height) {
        this.height = height;
        this.side = side;
    }

    public void calculateArea() {
        System.out.println("The Area of the Triangle: " + height * side);
    }

    public void calculatePerimeter() {
        System.out.println("The Perimeter of the Triangle: " + 3 * side);
    }
}

class Main {
    public static void main(String[] args) {
        Rectangle rec = new Rectangle(10, 20);
        Triangle t = new Triangle(10, 20);

        rec.calculatePerimeter();
        rec.calculateArea();
        t.calculatePerimeter();
        t.calculateArea();
    }
}