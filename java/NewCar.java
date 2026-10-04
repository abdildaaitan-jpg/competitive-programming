public class NewCar {
    public static void main(String[] args) {
        CarModel myCar = new CarModel(1969, "Mustang");
        CarModel yourCar = myCar;
        CarModel hisCar = null;
        hisCar = yourCar;

        System.out.println(hisCar.name + " " + hisCar.year);
    }
}