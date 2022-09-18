import java.util.Scanner;

public class Array_binary_Search {
    static Scanner tuu = new Scanner(System.in);

    public static void main(String[] args) {

        int[] arr = { 2, 3, 3, 3, 5, 12, 12, 12, 12, 15, 90 };
        System.out.println("Enter the number that you wanna find: ");
        int num = tuu.nextInt();

        int Lower_Bound = Lower_Bound(arr, num);
        System.out.println("The lower bound of the element " + num + " is: " + Lower_Bound);

        int Upper_Bound = Upper_Bound(arr, num);
        System.out.println("The upper bound of the element " + num + " is: " + Upper_Bound);
    }

    public static int Lower_Bound(int[] arr, int num) {

        int ans = -1;
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (arr[mid] == num) {
                ans = mid;
                high = mid - 1;
            } else if (arr[mid] > num) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }

    public static int Upper_Bound(int[] arr, int num) {

        int ans = -1;
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (arr[mid] == num) {
                ans = mid;
                low = mid + 1;
            } else if (arr[mid] > num) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
}
