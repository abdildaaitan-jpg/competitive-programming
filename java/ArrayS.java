import java.util.Scanner;
public class ArrayS {
    public static void main(String[] args) {
        final int maxn = (int) 1e9;
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] v = new int[n];
        int sum = 0, max = -maxn, min = maxn;

        for (int i = 0; i < v.length; i++) {
            v[i] = in.nextInt();
            sum += v[i];
            if (v[i] > max) max = v[i];
            if (v[i] < min) min = v[i];
        }
        System.out.println("Sum of all elements: " + sum);
        System.out.println("Average of all element: " + (sum * 1.0 / v.length));
        System.out.println("Max: " + max);
        System.out.println("Min: " + min);
        in.close();
    }
}