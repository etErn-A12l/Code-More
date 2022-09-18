public class Array_value_swap_3 {

    public static void main(String[] args) {

        int[] arr;
        arr = new int[5];

        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;

        for (int yuo : arr) {
            System.out.println(yuo);
        }

        int[] other = { 100, 200, 300 };
        System.out.println(arr[0] + " , " + other[0]);
        // Swapping the values
        Swap(arr, other);

        System.out.println(arr[0] + " , " + other[0]);

    }

    public static void Swap(int[] arr, int[] other) {
        
        int[] temp;
        temp = new int[1];
        temp[0] = arr[0];
        arr[0] = other[0];
        other[0] = temp[0];
    }
}
