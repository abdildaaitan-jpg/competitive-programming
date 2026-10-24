import java.util.*;
public class StringBuilderFile {
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        StringBuilder st = new StringBuilder(in.next());
        st.append(" <- is string ");
        st.setCharAt(st.length() - 1, '!');

        System.out.print(st);
    }
}