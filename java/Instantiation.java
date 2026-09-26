public class Instantiation {
    int age = 15;
    String name = "Akbol";
    public static void main(String[] args) {
        Instantiation x = new Instantiation();
        System.out.println(x.name);
        System.out.println(x.age);

        Instantiation_ y = new Instantiation_();
        System.out.println(y.name);
        System.out.println(y.age);
    }
}
