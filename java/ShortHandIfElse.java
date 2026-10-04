import java.util.Scanner;
public class ShortHandIfElse {
    public void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("How old are you? ");

        int myAge = input.nextInt();
        
        System.out.print("You are " + myAge + " years old. Am I right? Write 'true' - if true, otherwise 'false' ");
        boolean sub = input.nextBoolean();
        
        if (!sub) {
            System.out.print("Sorry, try again later.");
            input.close();
            return;
        }
        
        String mess = (myAge >= 18) ? "Congratulations, you have a full access." : "Sorry, you have no access.";

        System.out.print(mess);
        
        input.close();
    }
}
