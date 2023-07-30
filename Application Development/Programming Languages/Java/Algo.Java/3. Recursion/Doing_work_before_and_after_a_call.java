public class Doing_work_before_and_after_a_call {

    public static void main(String[] args) {

        int a = 5;

        print_it(a);
    }

    public static void print_it(int num) {

        if (num == 0) {
            return;
        }
        System.out.println(num);
        print_it(num - 1);
        System.out.println(num);
    }
}
