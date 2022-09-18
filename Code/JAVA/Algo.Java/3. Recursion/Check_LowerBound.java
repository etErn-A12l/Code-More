import java.util.Scanner;

public class Check_LowerBound {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        int arr[] = { 2, 3, 6, 9, 12, 6, 5, 12 };
        System.out.println("Enter the number: ");
        int num = scn.nextInt();
        int Index = find_lower_bound(arr, 0, num);

        System.out.println("The LowerBound of " + num + " is " + Index);
    }

    public static int find_lower_bound(int arr[], int index, int num) {

        if (index == arr.length) {
            return -1;
        }

        if (arr[index] == num) {
            return index;
        } else {
            int new1 = find_lower_bound(arr, index + 1, num);
            return new1;
        }
    }    
}
