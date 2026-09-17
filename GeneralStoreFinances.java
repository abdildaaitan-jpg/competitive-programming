public class GeneralStoreFinances {
    public static void main(String[] args) {
        double bankAccount = 18450.00;
        double cashRegister1 = 849.50;
        double cashRegister2 = 426.58;
        double cashRegister3 = 209.01;
        double safe = 1285.09;
        double supplier1 = 6700.00;
        double supplier2 = 400.00;
        double supplier3 = 10000.00;

        bankAccount = bankAccount - (supplier1 + supplier2 + supplier3);
        System.out.print("Balance remaining in bank account: ");
        System.out.println(bankAccount);

        double totalFromRegisters = cashRegister1 + cashRegister2 + cashRegister3;
        System.out.print("Money collected from registers: ");
        System.out.println(totalFromRegisters);
        System.out.print("Money in safe: ");
        System.out.println(safe);
        System.out.print("Difference: ");
        double difference = safe - totalFromRegisters;
        System.out.println(difference);
    }
}