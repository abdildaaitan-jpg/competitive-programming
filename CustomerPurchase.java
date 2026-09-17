import java.util.Scanner;
public class CustomerPurchase {
    public static void main(String[] args) {

        // Constant - the value of a quarter
        final double QUARTER_VALUE = 0.25;

        // create two variables:
        // total: records the running total
        // itemCount: counts the number of otems purchased
        double total = 0;
        int itemCount = 0;

        // The customer is buying sunscreen for $7.26
        // Add this amount to total and update itemCount by 1
        total += 7.26;
        itemCount++;

        // The customer is buying sunscreen for $7.26
        // Add this amount to total and update itemCount by 1
        total += 4.79;
        itemCount++;

        // The customer is buying flashlight for $12.99
        // Add this amount to total and update itemCount by 1
        total += 12.99;
        itemCount++;

        // The customer is buying chicken feed for $34.99 per bag
        // Ask the customer how many bags of chicken they would like 
        // Add this to your total and update your itemCount
        Scanner in = new Scanner(System.in);
        System.out.println("How many chicken feed would you like?");
        int numBags = in.nextInt();

        total += numBags * 34.99;
        itemCount += numBags;

        // Print out the total and the number of items purchased so far
        System.out.print("The total for the entire order is: $");
        System.out.println(total);
        System.out.print("The number of the items purchased is: ");
        System.out.println(itemCount);

        // Write an expression to calculate the sales tax (5%)
        // and add it to the total
        total *= 1.05;

        // Print out the total with sales tax
        System.out.print("The total with sales tax is now: $");
        System.out.println(total);

        // Given the payment listed below,
        // calculate and display the change to be given back
        double payment = 200.00;
        double change = payment - total;
        System.out.print("Your change is: $");
        System.out.println(change);
        // The customer wants their change in all quarters, 
        // how many quarters would that be?
        // Calculate the change in quarters and display the results
        int numQuarters = (int)(change / QUARTER_VALUE);
        System.out.print("Your change in all quarters is: ");
        System.out.print(numQuarters);
        System.out.println(" quarters.");
    }
}