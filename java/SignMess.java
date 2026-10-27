import java.util.*;
public class SignMess {
    static Scanner in = new Scanner(System.in);
    static void main(String[] args) {
        String mess = new String("Hello! My name is MESS. What is your name?");
        System.out.println(mess);
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