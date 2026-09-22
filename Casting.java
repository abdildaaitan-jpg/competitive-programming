public class Casting {
    public static void main(String[] args) {
        int a = 7, b = 2;
        double c = 9.8;

        double x = a / b;
        double y = (double) a / b;
        double z = (double) (a / b);
        int w = (int) c;

        System.out.println(x);
        System.out.println(y);
        System.out.println(z);
        System.out.println(w);
    }
}