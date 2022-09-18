
// package JAVA.Basics;

public class Data_Type_casting {
    public static void main(String args[]) {

        int apple = 14;
        double orange = apple; // automatically converts int to double as double > int
        System.out.println(apple); // returns 14
        System.out.println(orange); // returns 14.0
        double banana = 78.98d;
        int new_banana = (int) banana; // manually casting double to int as int < double
        System.out.println(banana); // returns 78.98
        System.out.println(new_banana); // returns 78

    }
}
