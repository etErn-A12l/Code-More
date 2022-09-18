public class Array_value_swap_1 {

    public static void main(String[] args) {
        int a = 2, b = 5;

        System.out.println(a + " , " + b);

        // swapping not working in main function
        swap(a, b);

        // if we print the values here, the numbers will be unchanged
    }

    // Swap function
    public static void swap(int a, int b) {

        int temp = a;
        a = b;
        b = temp;

        System.out.println(a + " , " + b);

    }
}
