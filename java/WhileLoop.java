import java.util.Scanner;
public class WhileLoop {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cnt = in.nextInt();
        
        while(cnt > 0) {
            System.out.println(cnt);
            cnt--;
        }
        System.out.print("Happy new year!");
        in.close();
    }
}