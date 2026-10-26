public class SignMessage {
    public static void main(String[] args) {
        String message = new String("Welcome to Bit's and Byte's General Store!");
        System.out.println(message);
        
        message = "Today's special is PIRATES! All PIRATES are 50% off!";
        
        String oldWord = "PIRATES";
        String newWord = "PLATES";

        int location = message.indexOf(oldWord);
        message = message.substring(0, location) + newWord + message.substring(location + oldWord.length());

        location = message.indexOf(oldWord);
        message = message.substring(0, location) + newWord + message.substring(location + oldWord.length());
        
        int percentage = (int) (Math.random() * 41) + 20;
        message = message.substring(0, message.indexOf("50")) + percentage + message.substring(message.indexOf("50") + 2);
        System.out.println(message);
    }
}
