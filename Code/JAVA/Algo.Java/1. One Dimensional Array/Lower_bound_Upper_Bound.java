import java.util.Scanner;

public class Lower_bound_Upper_Bound {

    static Scanner tuu = new Scanner(System.in);

    public static void main(String[] args) {

        int[] arr = { 2, 3, 3, 3, 3, 7, 12, 12, 12, 35, 35, 35, 35, 35, 90 };
        System.out.println("Enter the number that you wanna find: ");
        int num = tuu.nextInt();

        int Index = Binary_Search(arr, num);
        System.out.println("The index of the element " + num + " is: " + Index);
    }

    public static int Binary_Search(int[] arr, int num) {

        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (arr[mid] < num) {
                low = mid + 1;

            } else if (arr[mid] > num) {
                high = mid - 1;

            } else
                return mid;
        }
        return -1;
    }
}
