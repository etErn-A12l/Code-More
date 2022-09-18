// package JAVA.Basics;

public class Multidimensional_Array {
    public static void main(String[] args) {
        int arr[][] = { { 1, 2, 43, 4 }, { 123, 45, 76, 54, 56, 12 } };
        // System.out.println(arr[0][0]);   // Prints the very first element of the array
        // System.out.println(arr[1][1]);
        for (int i = 0; i < arr.length; ++i) {
            for (int j = 0; j < arr[i].length; ++j) {
                System.out.println(arr[i][j]);
            }
        }
    }
}
