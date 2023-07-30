
public class Factorial_Using_Recursion {

    public static void main(String[] args) {

        int num = 4;
        int ans = fact(num);
        System.out.println("Ans = " + ans);
    }

    public static int fact(int num) {

        if (num == 1) {
            return 1;
        }

        int alu = fact(num - 1);
        int ans = num * alu;

        return ans;
    }
}


