// package JAVA;

public class prime_number {
    public static void main(String args[]) {
        int num = 20;
        int check = 1;
        if (num > 2) {
            for (int i = 2; i < num; i++) {
                check = num % i;
                if (check == 0) {
                    break;
                }
            }
        }
        if (check == 0) {
            System.out.println("The given number is not a prime number !");
        } else {
            System.out.println("The given number is a prime number !");
        }
    }
}
