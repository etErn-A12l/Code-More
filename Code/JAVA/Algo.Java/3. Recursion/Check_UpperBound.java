import java.util.Scanner;

public class Check_UpperBound {

    public static Scanner ab = new Scanner(System.in);

    public static void main(String[] args) {

        int arr[] = { 2, 6, 4, 8, 3, 2, 8, 6, 3, 8 };
        int num;
        System.out.println("Enter the number that you wanna find: ");
        num = ab.nextInt();
        int result = -1;
        find_upper_bound(arr, 0, num, result);
    }

    public static int find_upper_bound(int arr[], int index, int num, int result) {
        if(index == arr.length)
        {
            return result;
        }

        if (arr[index] == num)
        {
            result = index;
        }
        else{
            result = find_upper_bound(arr, index+1, num, result);
        }

    }
}
