import java.util.Scanner;

public class Fibonacci_series_using_recursion {

    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.println("Enter the Index no. of the term you wanna print: ");
        int num = scn.nextInt();

        int ans = Print_Fibonacci(num);
        System.out.println("The " + num + "th term is " + ans);
    }

    public static int Print_Fibonacci(int num) {
        if (num == 0 || num == 1) {
            return num;
        }

        int fibo1 = Print_Fibonacci(num - 1);
        int fibo2 = Print_Fibonacci(num - 2);
        int fibo = fibo1 + fibo2;

        return fibo;
    }
}
