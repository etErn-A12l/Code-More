import java.util.Scanner;

public class user_input {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        // Takes an input of a string
        System.out.print("Enter a text baby: ");
        String text = input.nextLine();
        System.out.println("Here is your text " + text);

        // Takes an input of a intezer
        System.out.print("Enter a number baby: ");
        int a = input.nextInt();
        System.out.println("Here is your intezer : " + a);

    }
}
