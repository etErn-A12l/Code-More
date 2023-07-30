import java.util.Scanner;

public class user_input_array {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] array = new int[5];
        for (int i = 0; i < array.length; i++) {
            System.out.print("Enter: ");
            array[i] = scanner.nextInt();
        }
        scanner.close();

        System.out.println("Got All Inputs !");

        for (int i : array) {
            System.out.print(i + " ");
        }
    }
}
