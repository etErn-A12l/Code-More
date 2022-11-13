import java.util.Scanner;

public class Check_UpperBound {

    public static Scanner ab = new Scanner(System.in);

    public static void main(String[] args) {

        int arr[] = { 2, 6, 4, 8, 3, 2, 8, 6, 3, 8 };
        int num;
        System.out.print("Enter the number that you wanna find: ");
        num = ab.nextInt();
        int index = find_upper_bound(arr, 0, num);
        System.out.println("The Number was found at index: " + index);
    }

    public static int find_upper_bound(int arr[], int temp_index, int num) {
        
        if (temp_index == arr.length) {
            return -1;
        }

        int index = find_upper_bound(arr, temp_index + 1, num);
        if(index == -1)
        {
            if(arr[temp_index] == num)
                return temp_index;
            else
                return -1;
        }
        else {
            return index;
        }
    }
}
