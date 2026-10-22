import java.util.*;
public class EndOfLine {
    static Scanner in = new Scanner(System.in);
    
    public static void main(String[] args) {
        int cnt = 1;
        while (in.hasNext()) {
            String n = in.nextLine();
            System.out.println(cnt + " " + n);
            cnt++;
        }   
        in.close();
    }
}

