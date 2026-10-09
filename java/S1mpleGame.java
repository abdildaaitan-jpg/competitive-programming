import java.util.Scanner;
public class S1mpleGame {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = (int) (Math.random() * (10000)) + 1;
        String numStr = "" + num;
        System.out.println("The number consists " + numStr.length() + " digits.");
        System.out.println("Try finding the number: ");

        int guess = in.nextInt();

        while(guess != num) {
            if (guess > num) {
                System.out.println("Number is lower than yours.");
            }
            else {
                System.out.println("Number is higher than yours.");
            }
            guess = in.nextInt();
        }
        System.out.println("Congratulations, you guessed the number. It was " + num + ".");
    }
}