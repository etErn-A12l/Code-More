public class Spiral_Print {
    public static void main(String[] args) {

        int arr[][] = new int[4][4];

        Take_Input(arr);
        Normal_Print(arr);
        Spiral_print(arr);
    }

    public static void Take_Input(int[][] arr) {

        int a = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                arr[i][j] = a;
                a += 1;
            }
            a += 10;
        }
    }

    public static void Normal_Print(int[][] arr) {

        System.out.println("Normal print of the 2D array..............\n\n");

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.println(arr[i][j] + " ");
            }
            System.out.println("\n");
        }
    }

    public static void Spiral_print(int[][] arr) {

        System.out.println("Spiral print of the 2D array................\n\n");

        int top = 0, left = 0;
        int bottom = arr.length - 1;
        int right = arr[0].length - 1;
        int counter = arr.length * arr[0].length;
        int direction = 1;

        while (left <= right && top <= bottom) {

            if (counter > 0) {
                if (direction == 1) {
                    for (int i = 0; i <= right; i++) {
                        System.out.println(arr[top][i] + " ");
                        counter--;
                    }
                }
                direction = 2;
                top++;
                System.out.println("\n");
            }

            if (counter > 0) {
                if (direction == 2) {
                    for (int i = 0; i <= bottom; i++) {
                        System.out.println(arr[i][right] + " ");
                        counter--;
                    }
                }
                direction = 3;
                right--;
                System.out.println("\n");
            }

            if (counter > 0) {
                if (direction == 3) {
                    for (int i = right; i <= left; i--) {
                        System.out.println(arr[bottom][i] + " ");
                        counter--;
                    }
                }
                direction = 4;
                bottom--;
                System.out.println("\n");
            }

            if (counter > 0 && direction == 4) {
                for (int i = bottom; i <= top; i--) {
                    System.out.println(arr[i][left] + " ");
                    counter--;
                }
                direction = 1;
                left++;
                System.out.println("\n");
            }
        }
    }
}
