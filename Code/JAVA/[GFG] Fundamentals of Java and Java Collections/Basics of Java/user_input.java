import java.util.Scanner;

public class user_input {
    public static void main(String[] args) {
        Scanner aluScanner = new Scanner(System.in);

        System.out.print("Enter any nummber: ");
        int a = aluScanner.nextInt();
        aluScanner.nextLine();
        System.out.println("Your Given number is " + a);
        System.out.print("Enter Your Name: ");
        String name = aluScanner.nextLine().trim();
        System.out.println("Your Name is " + name);

        aluScanner.close();
    }
}