public class Instantiation {
    int age = 15;
    int year;
    String name = "Akbol";

    public static void Bye() {
        System.out.println("Bye bye!");
    }

    public static void main(String[] args) {
        Instantiation x = new Instantiation();
        x.year = 2026;
        System.out.println("---------- " + x.year + " ----------");
        System.out.println(x.name);
        System.out.println(x.age);

        Instantiation_ y = new Instantiation_();
        y.Hello();
        System.out.println(y.name);
        System.out.println(y.age);
        
        Bye();
    }
}
