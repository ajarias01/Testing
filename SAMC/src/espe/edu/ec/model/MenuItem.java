package espe.edu.ec.model;

import java.util.ArrayList;
import java.util.List;

public class MenuItem {
    private static List<MenuItem> menuItems = new ArrayList<>();
    private String name;
    private String description;
    private float price;
    private int id;
    private int inventory;

    public MenuItem(int id, String name, String description, float price, int inventory) {
        this.id = id;
        this.name = name;
        this.description = description;
        this.price = price;
        this.inventory = inventory;
        menuItems.add(this);
    }
    public static void initializeMenu() {
        if (menuItems.isEmpty()) {
        new MenuItem(1, "Guata pequenia", "Plato tradicional de guata", 1.50f, 50);
        new MenuItem(2, "Guata mediana", "Plato tradicional de guata", 2.00f, 30);
        new MenuItem(3, "Guata extragrande", "Plato tradicional de guata", 2.50f, 20);
        new MenuItem(4, "Papas con cuero", "Papas con cuero", 2.00f, 25);
        new MenuItem(5, "Seco de chivo", "Plato con carne de chivo", 2.50f, 15);
        new MenuItem(6, "Seco de chancho", "Plato con carne de chancho", 2.50f, 15);
        new MenuItem(7, "Seco de costilla", "Plato con costilla", 2.50f, 15);
        new MenuItem(8, "Seco de pollo", "Plato con carne de pollo", 2.50f, 15);
        new MenuItem(9, "Mixto seco de pollo y guata", "Mezcla de pollo y guata", 3.50f, 15);
        new MenuItem(10, "Mixto seco de costilla y guata", "Mezcla de costilla y guata", 3.50f, 15);
        new MenuItem(11, "Mixto papas con cuero y guata", "Mezcla de papas con cuero y guata", 3.50f, 15);
        new MenuItem(12, "Mixto seco de chivo y guata", "Mezcla de chivo y guata", 3.50f, 15);
        new MenuItem(13, "Mixto seco de chancho y guata", "Mezcla de chancho y guata", 3.50f, 15);
        new MenuItem(14, "Mixto seco de pollo y papas con cuero", "Mezcla de pollo y papas con cuero", 3.50f, 15);
        new MenuItem(15, "Mixto seco de chancho y papas con cuero", "Mezcla de chancho y papas con cuero", 3.50f, 15);
        new MenuItem(16, "Mixto seco de costilla y papas con cuero", "Mezcla de costilla y papas con cuero", 3.50f, 15);
        new MenuItem(17, "Mixto seco de chivo y papas con cuero", "Mezcla de chivo y papas con cuero", 3.50f, 15);
        new MenuItem(18, "Mixto con doble carne; pollo, chivo, chancho, costilla", "Plato con doble carne", 4.50f, 15);
        new MenuItem(19, "Banderas", "Plato especial de banderas", 6.75f, 15);
        }
    }
    public static void displayMenu() {
        System.out.println("ID\tNombre\t\tDescripcion\t\tPrecio\tInventario");
        for (MenuItem item : menuItems) {
            System.out.printf("%d\t%s\t%s\t%.2f\t%d\n", item.id, item.name, item.description, item.price, item.inventory);
        }
    }

    public static MenuItem getMenuItemById(int id) {
        for (MenuItem item : menuItems) {
            if (item.id == id) {
                return item;
            }
        }
        return null;
    }

    public void reduceInventory(int quantity) {
        if (quantity <= inventory) {
            inventory -= quantity;
        } else {
            System.out.println("No hay suficiente inventario para " + name);
        }
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    public float getPrice() {
        return price;
    }

    public int getInventory() {
        return inventory;
    }

    

    public static List<MenuItem> getMenuItems() {
        return menuItems;
    }

    public int getId() {
        return id;
    }
}