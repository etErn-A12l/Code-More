public class Power_Using_Recursion {

    public static void main(String[] args) {
        Integer num = 2;
        Integer power = 3;

        Integer ans = Power_recursion(num, power);
        System.out.println("The answer is " + ans);
    }

    public static int Power_recursion(int num, int power) {
        
        if (power == 0) {
            return 1;
        }

        int temp = Power_recursion(num, power-1);
        int ans = num*temp;
        
        return ans;
    }
}