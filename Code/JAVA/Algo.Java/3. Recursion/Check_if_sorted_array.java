public class Check_if_sorted_array {

    public static void main(String[] args) {
        int arr[] = { 2, 5, 7, 8, 9, 10, 11 };
        int Index = 0;

        boolean ans = check_sorted(arr, Index);

        if (ans == true) {
            System.out.println("The array is sorted !");
        } else {
            System.out.println("The array is not sorted !");
        }
    }

    public static boolean check_sorted(int arr[], int Index) {
        // Handling the exception
        if ((Index + 1) == arr.length) {
            return true;
        }

        if (arr[Index] > arr[Index + 1]) {
            return false;
        } else {
            boolean restval = check_sorted(arr, Index + 1);
            return restval;
        }
    }
}
