
public class Basic_Num_Print_ascending {

    public static void main(String[] args) {

        Ascending_recursion_print(5);
    }

    public static void Ascending_recursion_print(int num) {
        if (num == 0) {
            return;
        }
        Ascending_recursion_print(num - 1);
        System.out.println(num);
    }
}
