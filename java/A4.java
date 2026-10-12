import java.util.Scanner;
public class A4 {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        
        if (a == 2) {
            System.out.print("NO");
        }
        else if (a % 2 == 0) {
            System.out.print("YES");
        }
        else {
            System.out.print("NO");
        }
        in.close();
    }
}