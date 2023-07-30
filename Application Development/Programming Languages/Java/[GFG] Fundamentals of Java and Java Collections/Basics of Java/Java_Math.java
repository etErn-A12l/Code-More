// package JAVA.Basics;

public class Java_Math {
    public static void main(String[] args) {

        System.out.println(Math.max(12, 54)); // returns the greater number among the two
        System.out.println(Math.min(12, 54)); // returns the lower number among the two
        System.out.println(Math.sqrt(49)); // returns the square root of the given number
        System.out.println(Math.abs(-2836)); // returns the positive value of the given number i.e, 2836
        int num = (int) Math.random() * Integer.MAX_VALUE; // returns a random integer
        double nu = (double) (Math.random() * 201); // returns a random intezer between 0 - 200
        System.out.println(nu);
        System.out.println(num);
    }
}
