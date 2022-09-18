// Sorts the array in ascending order

public class Array_Selection_sort {
    public static void main(String[] args) {

        int[] arr = { 12, 3, 67, 35, 90 };

        Display(arr);
        Selection_Sort(arr);
        Display(arr);

    }

    public static void Selection_Sort(int[] arr) {

        for (int counter = 0; counter < arr.length - 1; counter++) {

            int min = counter;
            for (int j = counter + 1; j < arr.length; j++) {

                if (arr[j] < arr[min]) {
                    min = j;
                }
            }

            int temp = arr[counter];
            arr[counter] = arr[min];
            arr[min] = temp;

        }
    }

    public static void Display(int[] arr) {

        System.out.println("_____________________________\nYour entered values are : \n");

        for (int i = 0; i < arr.length; i++) {

            System.out.println((i + 1) + "th element : " + arr[i]);
        }

    }
}
