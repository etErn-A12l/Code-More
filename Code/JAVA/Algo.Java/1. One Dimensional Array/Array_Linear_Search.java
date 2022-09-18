import java.util.Scanner;

// This program returns the index of an element if it is present in the array 

public class Array_Linear_Search {
    static Scanner bb = new Scanner(System.in);

    public static void main(String[] args) {

        int[] arr = { 12, 3, 67, 35, 90 };

        System.out.println("Enter the number that you wanna find: ");
        int num = bb.nextInt();
        // System.out.println(num);
        int Index = Linear_Search(arr, num);

        if (Index == -1) {
            System.out.println("The number " + num + " is not present in the array !");
        } else {
            System.out.println("The Index of " + num + " is: " + Index);
        }
    }

    public static int Linear_Search(int[] arr, int num) {

        int Index = -1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num) {
                Index = i;
            }
        }
        return Index;
    }
}
