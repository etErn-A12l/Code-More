public class Basic_Num_Print {

    public static void main(String[] args) {

        print_decreasing_num(5);
    }

    public static void print_decreasing_num(int num) {

        System.out.println(num);
        if (num > 0) {
            print_decreasing_num(num - 1);
        }
    }
}