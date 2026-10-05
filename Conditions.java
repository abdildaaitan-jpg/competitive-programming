import java.util.Scanner;
public class Conditions {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x = input.nextInt(), y = input.nextInt();
        if (x > y) {
            System.out.println(x + " is greater than " + y);
        }        
        else if (x < y) {
            System.out.println(y + " is greater than " + x);
        }
        else {
            System.out.println(x + " is equal to " + y);
        }
        input.close();
        // conditions 
    }
}