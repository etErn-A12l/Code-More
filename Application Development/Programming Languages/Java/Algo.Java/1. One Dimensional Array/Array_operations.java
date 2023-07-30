import java.util.Scanner;

public class Array_operations {
    static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        int[] array = Take_Input();

        Display(array);
    }

    public static int[] Take_Input() {

        // Takes input from the user
        System.out.println("Size of the Array : ");
        int size = scn.nextInt();

        int[] arr = new int[size];

        for (int i = 0; i < arr.length; i++) {
            System.out.println("Value of the " + (i + 1) + "th element: ");
            arr[i] = scn.nextInt();
        }

        return arr;
    }

    public static void Display(int[] arr) {

        System.out.println("_____________________________\nYour entered values are : \n");

        for (int i = 0; i < arr.length; i++) {
            System.out.println((i + 1) + "th element : " + arr[i]);
        }

    }
}
