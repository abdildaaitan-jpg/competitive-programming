import java.util.*;

public class Solution {

    public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            System.out.println("================================");
            for(int i = 0; i < 3; i++){
                String s1 = in.next();
                int x = in.nextInt();
                
                int n = s1.length();
                System.out.print(s1);
                for (int l = n; l < 15; l++) System.out.print(" ");
                
                
                String s2 = x + "";
                for (int l = s2.length(); l < 3; l++) System.out.print(0); 
                System.out.println(x);
            }
            System.out.println("================================");
            in.close();
    }
}



