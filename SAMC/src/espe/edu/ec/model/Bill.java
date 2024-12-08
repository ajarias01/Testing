package espe.edu.ec.model;

import java.util.Map;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Bill {
    private Customer customer;
    private Map<String, Integer> order;
    private float total;
    private String date;

    public Bill(Customer customer, Map<String, Integer> order, float total) {
        this.customer = customer;
        this.order = order;
        this.total = total;
        this.date = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date());
    }

    public String getDate() {
        return date;
    }
    private float calculateTotal() {
        float total = 0.0f;
        for (Map.Entry<String, Integer> entry : order.entrySet()) {
            MenuItem item = MenuItem.getMenuItemById(getMenuItemIdByName(entry.getKey()));
            if (item != null) {
                total += item.getPrice() * entry.getValue();
            }
        }
        return total;
    }

    private int getMenuItemIdByName(String name) {
        for (MenuItem item : MenuItem.getMenuItems()) {
            if (item.getName().equalsIgnoreCase(name)) {
                return item.getId();
            }
        }
        return -1;
    }

    public Customer getCustomer() {
        return customer;
    }

    public Map<String, Integer> getOrder() {
        return order;
    }

    public float getTotal() {
        return total;
    }

   public String getOrderDetails() {
        StringBuilder details = new StringBuilder();
        for (Map.Entry<String, Integer> entry : order.entrySet()) {
            MenuItem item = MenuItem.getMenuItemById(getMenuItemIdByName(entry.getKey()));
            if (item != null) {
                details.append(String.format("Nombre: %s, Descripcion: %s, Precio: %.2f, Cantidad: %d\n",
                        item.getName(), item.getDescription(), item.getPrice(), entry.getValue()));
            }
        }
        return details.toString();
    }
    public String getCustomerDetails() {
        return String.format("ID: %d\nNombre: %s\nEmail: %s\nDireccion: %s\nTelefono: %s",
                customer.getId(), customer.getName(), customer.getEmail(), customer.getAddress(), customer.getPhoneNumber());
    }
     @Override
    public String toString() {
        return "Factura:\n" +
                getCustomerDetails() + "\n" +
                "Fecha: " + getDate() + "\n" +
                "Detalles del Pedido:\n" + getOrderDetails() +
                "Total: $" + getTotal();
    }
}