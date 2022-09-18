public class Basic_Num_PDISKIP {

    public static void main(String[] args) {

        int num = 5;
        PIDSKIP(num);

    }

    public static void PIDSKIP(int num) {

        if (num == 0) {
            return;
        }

        if (num % 2 == 0) {
            PIDSKIP(num - 1);
            System.out.println(num);
        } else {
            System.out.println(num);
            PIDSKIP(num - 1);
        }
    }
}
