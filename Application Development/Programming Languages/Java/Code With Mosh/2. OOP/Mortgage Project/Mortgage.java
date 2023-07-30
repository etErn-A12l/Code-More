import java.util.Scanner;
import java.text.NumberFormat;

public class Mortgage {

    private int Principal;
    private float Rate;
    private int Period;

    public void getInput() {

        setPrincipal((int) inputValidator("Principal Amount"));
        setRate(inputValidator("Interest Rate"));
        setPeriod((int) inputValidator("Time Period"));
    }

    private float inputValidator(String Promt) {

        Scanner sx = new Scanner(System.in);
        float Input;
        while (true) {
            System.out.print("Enter " + Promt + ": ");
            Input = sx.nextFloat();
            if (Input > 0) {
                return Input;
            } else {
                System.out.print("Invalid " + Promt + " ! ");
            }
        }

    }

    public void mortgageCalculate() {

        double Interest = (getPrincipal() * getRate() * getPeriod()) / 100;
        double totalPayable = Interest + getPrincipal();
        double perMonth = totalPayable / (getPeriod() * 12);

        NumberFormat pay = NumberFormat.getCurrencyInstance();

        System.out.println("\nTotal Payable: " + pay.format(totalPayable));
        System.out
                .println("\nYou Need to Pay " + pay.format(perMonth) + " Every Month, For " + getPeriod() + " Years !");

        double temp = totalPayable;
        short month = 1;
        System.out.println("\nPer Month Scheduled: \n");
        System.out.println("----------------------------------------------------------------\n");
        while (temp >= 0) {
            System.out.println(month + "th Month Due: " + pay.format(temp));
            temp -= perMonth;
            month++;
        }
        System.out.println("----------------------------------------------------------------");

    }

    private int getPrincipal() {
        return Principal;
    }

    private void setPrincipal(int principal) {
        Principal = principal;
    }

    private float getRate() {
        return Rate;
    }

    private void setRate(float rate) {
        Rate = rate;
    }

    private int getPeriod() {
        return Period;
    }

    private void setPeriod(int period) {
        Period = period;
    }
}
