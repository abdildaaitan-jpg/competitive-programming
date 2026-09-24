import java.util.Scanner;
public class CallingClassMethods {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter student name: ");
        String name = input.next();
        System.out.print("Enter score 1: ");
        int score1 = input.nextInt();
        System.out.print("Enter score 2: ");
        int score2 = input.nextInt();
        System.out.print("Enter score 3: ");
        int score3 = input.nextInt();

        double average_score = CallingClassMethods.average(score1, score2, score3);

        int highest_score = CallingClassMethods.max(max(score1, score2), score3);
        
        int total = CallingClassMethods.add(add(score1, score2), score3);

        CallingClassMethods.print_report(name, average_score, highest_score, total);
        input.close();
    }
    public static int add(int a, int b) {
        return a + b;
    }
    public static double average(int a, int b, int c) {
        return (a + b + c) / 3.0;
    }
    public static int max(int a, int b) {
        return Math.max(a, b);
    }
    public static void print_report(String name, double average, int highest, int total) {
        System.out.println("----- Student Report -----");
        System.out.println("Student: " + name);
        System.out.println("Average: " + average);
        System.out.println("Highest score: " + highest);
        System.out.print("Total score: " + total);
    }
}