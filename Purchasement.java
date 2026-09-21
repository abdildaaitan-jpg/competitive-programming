import java.util.Scanner;
public class Purchasement {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int price = input.nextInt(), quantity = input.nextInt(), discount = input.nextInt();
        int total = price * quantity - discount;
        input.close();
        System.out.print("Final price: " + total);
    }
}
