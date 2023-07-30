public class CustomConstructor {
    private int apple;
    private int orange;

    public CustomConstructor(int apple, int orange) {
        setApple(apple);
        setOrange(orange);
    }

    public CustomConstructor(int apple) { // Constructor Overloading
        this(apple, 0); // Passing values to Previous constructor
    }

    public double bill() {
        return (getApple() * 23 + getOrange() * 21);
    }

    private int getApple() {
        return apple;
    }

    private void setApple(int apple) {
        this.apple = apple;
    }

    private int getOrange() {
        return orange;
    }

    private void setOrange(int orange) {
        this.orange = orange;
    }
}
