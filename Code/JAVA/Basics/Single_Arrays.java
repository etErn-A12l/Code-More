// package JAVA.Basics;

public class Single_Arrays {
    public static void main(String[] args) {
        String[] arr = { "ami", "vat", "khai", "kintu", "amar", "valo", "lage", "na" };
        // System.out.println(arr[4]);
        // arr[4] = "karor";
        // System.out.println(arr[4]);
        for (String i : arr) {
            System.out.println(i);  // One method to print elements of an array
        }

        System.out.println(arr.length);

        for(int q = 0;q<arr.length;q++){    // Second method to print elements of an array
            System.out.println(arr[q]);
        }
    }
}
