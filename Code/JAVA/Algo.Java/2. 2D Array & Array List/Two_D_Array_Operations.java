import java.util.Scanner;

public class Two_D_Array_Operations {
    static Scanner s = new Scanner(System.in);

    public static void main(String[] args) {

        int[][] arr = TakeInput();
        Display(arr);
    }

    public static int[][] TakeInput() {

        System.out.println("Enter the number of rows of your array: ");
        int row = s.nextInt();
        System.out.println("Enter the number of coloumns of your array: ");
        int coloumn = s.nextInt();

        int arr[][] = new int[row][];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[coloumn];
            for (int j = 0; j < coloumn; j++) {
                System.out.println("Enter element of " + (i + 1) + "th row, " + (j + 1) + "th coloumn: ");
                arr[i][j] = s.nextInt();
            }
        }
        return arr;
    }

    public static void Display(int arr[][]) {

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.println("The element of " + (i + 1) + "th row, " + (j + 1) + "th coloumn is: "+arr[i][j]);
            }
        }
    }
}
