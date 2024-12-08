package espe.edu.ec.model;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
/**
 *
 * @author Robinson Bonilla
 */
public class BeverageInventory {
    private List<Beverage> beverages;
    private static final int LOW_STOCK_THRESHOLD = 5;

    public BeverageInventory() {
        this.beverages = new ArrayList<>();
    }

    // Método para agregar una bebida al inventario
    public void addBeverage(Beverage beverage) {
        beverages.add(beverage);
        System.out.println("Bebida agregada: " + beverage.getName());
    }

    // Método para eliminar una bebida del inventario por nombre
    public void removeBeverage(String name) {
        beverages.removeIf(beverage -> beverage.getName().equalsIgnoreCase(name));
        System.out.println("Bebida eliminada: " + name);
    }

    // Método para vender una bebida a un cliente
    public void sellBeverage(String name) {
        for (Beverage beverage : beverages) {
            if (beverage.getName().equalsIgnoreCase(name)) {
                if (beverage.getQuantity() > 0) {
                    beverage.setQuantity(beverage.getQuantity() - 1);
                    System.out.println("Bebida vendida: " + beverage.getName());
                    if (beverage.getQuantity() <= LOW_STOCK_THRESHOLD) {
                        System.out.println("Advertencia: Stock bajo de " + beverage.getName() + ". Quedan " + beverage.getQuantity() + " unidades.");
                    }
                } else {
                    System.out.println("No hay stock suficiente de " + beverage.getName() + ".");
                }
                return;
            }
        }
        System.out.println("La bebida " + name + " no se encuentra en el inventario.");
    }

    // Método para listar todas las bebidas en el inventario una por una
    public void listBeverages() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Inventario de bebidas:");
        for (Beverage beverage : beverages) {
            System.out.println(beverage);
            System.out.println("Presiona Enter para ver la siguiente bebida...");
            scanner.nextLine(); // Espera a que el usuario presione Enter antes de continuar
        }
    }

    // Clase interna para representar una bebida
    public static class Beverage {
        private String name;
        private double price;
        private int quantity;

        public Beverage(String name, double price, int quantity) {
            this.name = name;
            this.price = price;
            this.quantity = quantity;
        }

        public String getName() {
            return name;
        }

        public double getPrice() {
            return price;
        }

        public int getQuantity() {
            return quantity;
        }

        public void setQuantity(int quantity) {
            this.quantity = quantity;
        }

        @Override
        public String toString() {
            return "Bebida{" +
                    "nombre='" + name + '\'' +
                    ", precio=" + price +
                    ", cantidad=" + quantity +
                    '}';
        }
    }
}
