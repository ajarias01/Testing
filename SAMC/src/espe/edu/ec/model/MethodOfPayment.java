package espe.edu.ec.model;

import java.util.Scanner;

public class MethodOfPayment {

    public String choosePaymentMethod() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Seleccione método de pago:");
        System.out.println("1. Efectivo");
        System.out.println("2. Transferencia");

        int choice = scanner.nextInt();
        scanner.nextLine();

        switch (choice) {
            case 1:
                return "Efectivo";
            case 2:
                return "Transferencia";
            default:
                System.out.println("Opción inválida. Por defecto: Efectivo.");
                return "Efectivo";
        }
    }
}
