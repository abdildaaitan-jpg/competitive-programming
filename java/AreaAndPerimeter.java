import java.util.Scanner;
public class AreaAndPerimeter {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("----- Rectangle -----");

        // Taking lenght and width from user
        int a = input.nextInt(), b = input.nextInt();

        int A = a * b;
        int P = 2 * (a + b);

        // Printing variables
        System.out.println("Lenght: " + a);
        System.out.println("Width: " + b);

        System.out.println("Area: " + A);
        System.out.println("Perimeter: " + P);

        circle();
        input.close();
    }
    public static void circle() {
        Scanner input = new Scanner(System.in);
        final double p = 3.14;
        System.out.println("----- Circle -----");

        int r = input.nextInt();

        double A = p * Math.pow(r, 2);
        double P = 2 * p * r;

        System.out.println("Radius: " + r);

        System.out.println("Area: " + A);
        System.out.println("Perimeter: " + P);
        input.close();
    }
}