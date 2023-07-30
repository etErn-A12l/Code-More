import java.lang.Math.*;

public class test {
    public static void main(String args[]) {
        int n = 67, temp;
        double count = 0, sum = 0;
        double rem;
        temp = n;
        while (temp != 0) {
            temp = temp / 10;
            count = count + 1;
        }
        temp = n;
        while (temp != 0) {
            rem = temp % 10;
            sum = sum + Math.pow(rem, count);
            temp = temp / 10;

        }
        System.out.println(sum);
    }
}