import java.util.ArrayList;

public class ArrayList_operation {

    public static void main(String[] args) {

        ArrayList<Integer> arr = new ArrayList<>();

        System.out.println(arr);
        System.out.println(arr.size());

        arr.add(789);
        System.out.println(arr);
        System.out.println(arr.size());
        arr.add(54);
        System.out.println(arr);
        System.out.println(arr.size());
        arr.add(76);
        System.out.println(arr);
        System.out.println(arr.size());
        arr.add(868);
        System.out.println(arr);
        System.out.println(arr.size());
        arr.add(64);
        System.out.println(arr);
        System.out.println(arr.size());

        System.out.println(arr.get(3));
        arr.remove(3);

        System.out.println(arr);
        System.out.println(arr.size());
    }
}
