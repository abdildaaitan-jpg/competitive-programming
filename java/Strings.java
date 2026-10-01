public class Strings {
    public static void main(String[] args) {
        String str = "Computer";
        
        String substr = str.substring(0, 6);

        System.out.println(substr);
        // Comput
        System.out.println(str.indexOf("puter") + "\n" + str.indexOf("a"));
        // 3 
        // -1
        System.out.println(str.equals("Computer"));
        // true        
        System.out.println(str.compareTo("Computer") + " " + str.compareTo("ABC"));
        // 0 2

        String hello = "hello";

        System.out.println(hello.toUpperCase());
        // HELLO
        System.out.println(hello.toUpperCase().toLowerCase());
        // hello

        
        System.out.println(hello);
        // hello
        hello = hello.toUpperCase();

        System.out.println(hello);
        // HELLO
    }
}