public class Calculator {

    public static int add(int a, int b) {
        return a + b;
    }

    public static double multiply(double a, double b) {
        return a * b;
    }

    public static void main(String[] args) {

        int x = 7;
        int y = 3;

        int result1 = Calculator.add(x, y);
        double result2 = Calculator.multiply(result1, 2.5);

        System.out.println(result1);
        System.out.println(result2);
    }
}