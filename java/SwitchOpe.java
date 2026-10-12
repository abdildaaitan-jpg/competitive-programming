import java.util.Scanner;
public class SwitchOpe {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int day = in.nextInt();
        switch (day) {
            case 1:
                print("Monday");
                break;
            case 2: 
                print("Tuesday");
                break;
            case 3:
                print("Wednesday");
                break;
            case 4: 
                print("Thursday");
                break;
            case 5: 
                print("Friday");
                break;
            case 6: 
                print("Saturday");
                break;
            case 7: 
                print("Sunday");
                break;
            default:
                print("Error");
        }
        in.close();
    }
    static void print(String day) {
        System.out.print(day);
    }
}