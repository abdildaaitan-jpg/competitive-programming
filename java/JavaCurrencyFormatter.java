import java.util.*;

public class JavaCurrencyFormatter {    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double payment = scanner.nextDouble();
        
        String us, india, china, france;
        us = india = china = france = payment + "";
        
        System.out.println("US: " + us);
        System.out.println("India: " + india);
        System.out.println("China: " + china);
        System.out.println("France: " + france);
        
        scanner.close();
    }
}