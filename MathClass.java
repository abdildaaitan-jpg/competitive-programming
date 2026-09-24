public class MathClass {
    public static void main(String[] args) {
        System.out.println(Math.max(20, 50));
        // 50
        
        System.out.println(Math.min(20, 50));
        // 20

        System.out.println(Math.sqrt(81));
        // 9.0

        System.out.println(Math.abs(-30));
        // 30

        System.out.println(Math.pow(2, 4));
        // 16.0

        System.out.println(Math.round(4.6));
        // 5

        System.out.println(Math.ceil(4.1));
        // 5.0

        System.out.println(Math.floor(4.9));
        // 4.0

        System.out.println(Math.random());
        // [0.0, 1.0)

        System.out.println((int) (Math.random() * (50 - 20 + 1)) + 20);
        // [20, 50]
    }
}
