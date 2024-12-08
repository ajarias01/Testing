package espe.edu.ec.model;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Map;

public class SaleNote {
    private Customer customer;
    private Map<String, Integer> order;
    private float total;
    private String date;

    public SaleNote(Customer customer, Map<String, Integer> order, float total) {
        this.customer = customer;
        this.order = order;
        this.total = total;
        this.date = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date());
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

    public String getDate() {
        return date;
    }

    @Override
    public String toString() {
        return "Nota de Venta{" +
                "Fecha: " + date +
                ", Cliente: " + customer.getName() +
                ", Platos Pedidos: " + order +
                ", Total: $" + total +
                '}';
    }
}