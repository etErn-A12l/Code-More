public class Array_Bubble_Sort {
    public static void main(String[] args) {

        int[] arr = { 12, 3, 67, 35, 90 };

        Display(arr);
        bubble_sort(arr);
        Display(arr);
    }

    public static void bubble_sort(int[] arr) {

        for (int counter = 0; counter < arr.length - 1; counter++) {

            for (int i = 0; i < arr.length - 1 - counter; i++) {

                if (arr[i] > arr[i + 1]) {

                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        }
        System.out.println("\nArray sorted successfully !");
    }

    public static void Display(int[] arr) {

        System.out.println("_____________________________\nYour entered values are : \n");

        for (int i = 0; i < arr.length; i++) {

            System.out.println((i + 1) + "th element : " + arr[i]);
        }

    }
}
