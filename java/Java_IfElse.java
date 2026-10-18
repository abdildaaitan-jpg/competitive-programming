import java.util.*;
public class Java_IfElse {
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        int n = in.nextInt();
        
        if (n % 2 != 0) {
            System.out.print("Weird");
        }
        else if (n >= 2 && n <= 5) {
            System.out.print("Not Weird");
        }
        else if (n >= 6 && n <= 20) {
            System.out.print("Weird");
        }
        else if (n > 20) {
            System.out.print("Not Weird");
        }
        in.close();
    }
}
