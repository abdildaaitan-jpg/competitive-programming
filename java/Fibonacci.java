import java.util.*;
class Fibonacci {
    static Scanner in = new Scanner(System.in);
    static void main(String[] args) {
        int number;
        
        System.out.print("Which number do you want to see? ");

        number = in.nextInt();
        System.out.print("The " + number + outPut(number) + "number is " + fib(number));
    }

    static int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        return fib(n - 1) + fib(n - 2);
    }

    static String outPut(int n) {
        if (n % 10 == 1) return "'st ";
        else if (n % 10 == 2) return "'nd ";
        else if (n % 10 == 3) return "'rd ";
        else return "'th ";
    }
}