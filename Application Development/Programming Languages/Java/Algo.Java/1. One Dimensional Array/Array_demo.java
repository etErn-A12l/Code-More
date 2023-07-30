
public class Array_demo {

    public static void main(String[] args) {

        // Declare
        int[] arr = null;
        System.out.println(arr);

        // Alocating space
        arr = new int[5];
        System.out.println(arr);
        int b = 10;

        // Stores value in the array
        for (int i = 0; i < arr.length; i++) {
            arr[i] = b;
            b += 10;
        }

        // Prints the value of the array
        for (int i = arr.length - 1; i >= 0; i--) {
            System.out.println(arr[i]);
        }

        System.out.println("Normal for loop ended !");

        // Enhanched for loop
        for (int val : arr) {
            System.out.println(val);
        }
    }
}