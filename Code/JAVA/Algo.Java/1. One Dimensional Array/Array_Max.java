
// This programm returns the maximum value of an array 

import java.util.Scanner;

public class Array_Max {
    static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        int[] arr = Take_Input();
        int Max = Determine_Max(arr);

        System.out.println("The maximum value of the array is : " + Max);
    }

    public static int[] Take_Input() {

        int[] arr = new int[5];

        for (int i = 0; i < arr.length; i++) {
            System.out.println("Enter the value of the element of the array: ");
            arr[i] = scn.nextInt();
        }
        return arr;
    }

    public static int Determine_Max(int[] arr) {
        int MAX = Integer.MIN_VALUE;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > MAX) {
                MAX = arr[i];
            }
        }
        return MAX;
    }
}
