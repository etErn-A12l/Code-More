public class Array_value_swap_2 {
    public static void main(String[] args) {

        int[] arr = null;
        int b = 10;
        arr = new int[5];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = b;
            b += 10;
        }

        for (int num : arr) {
            System.out.println(num);
        }

        // Swapping starts now
        int i = 2, j = 4;
        System.out.println(arr[i] + " , " + arr[j]);
        Swap(arr, i, j);
        System.out.println(arr[i] + " , " + arr[j]);

    }

    public static void Swap(int[] arr, int i, int j) {

        // System.out.println(arr[i] + " , " + arr[j]);
        // Swaps the value
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        // System.out.println(arr[i] + " , " + arr[j]);
    }
}
