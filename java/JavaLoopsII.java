import java.util.*;
public class JavaLoopsII {
    
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        int q = in.nextInt();
        for (int i = 1; i <= q; i++) {
            int a, b, n;
            a = in.nextInt();
            b = in.nextInt();
            n = in.nextInt();

            int p = a + b;
            for (int l = 1; l <= n; l++) {
                System.out.print(p + " ");
                p += Math.pow(2, l) * b;
            }
            System.out.println();
        }
        in.close();
    }
}
