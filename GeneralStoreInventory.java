public class GeneralStoreInventory {
    public static void main(String[] args) {
        int chickenFeedBacks = 200;
        int gardeningShovels = 42;
        int dustTape = 27;
        int toothpaste = 18;
        int lightBulbs = 150;
        int sunglasses = 38;

        System.out.print("Bags Of Chicken Feed = ");
        System.out.println(chickenFeedBacks);
        System.out.print("Gardening Shovels = ");
        System.out.println(gardeningShovels);
        System.out.print("Dust Tape = ");
        System.out.println(dustTape);
        System.out.print("Toothpaste = ");
        System.out.println(toothpaste);
        System.out.print("Light Bulbs = ");
        System.out.println(lightBulbs);
        System.out.print("Sunglasses = ");
        System.out.println(sunglasses);

        System.out.print("Total Sunglasses, Toothpaste and Light Bulbs = ");
        int total = toothpaste + sunglasses + lightBulbs;
        System.out.println(total);
    }
}