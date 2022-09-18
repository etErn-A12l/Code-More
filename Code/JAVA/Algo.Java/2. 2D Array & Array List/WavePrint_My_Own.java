public class WavePrint_My_Own {

    public static void main(String[] args) {

        int[][] arr = new int[4][4];

        Store_Value(arr);
        Wave_Print_Display(arr);
    }

    public static void Store_Value(int[][] arr) {

        int a = 11;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                arr[i][j] = a;
                a += 1;
            }
            a += 6;
        }
    }

    public static void Wave_Print_Display(int[][] arr) {

        for (int i = 0; i < arr.length; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < arr[i].length; j++) {
                    System.out.println(arr[i][j] + " ");
                }
            } else {
                for (int j = (arr[i].length - 1); j >= 0; j--) {
                    System.out.println(arr[i][j] + " ");
                }
            }
            System.out.println("\n");
        }
    }
}
