import java.util.*;
public class SignMess {
    static final Scanner in = new Scanner(System.in);
    static void main(String[] args) {
        String mess = in.nextLine();

        System.out.print("Enter the word that you want to change: ");
        String oldWord = in.next();
        System.out.print("How do you want to change it: ");
        String newWord = in.next();

        int loc = mess.indexOf(oldWord);
        mess = mess.substring(0, loc) + newWord + mess.substring(loc + oldWord.length());
        System.out.println(mess);
        
        in.close();
    }
}