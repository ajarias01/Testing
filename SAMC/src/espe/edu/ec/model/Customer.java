package espe.edu.ec.model;

import java.util.List;

public class Customer {
    private static int nextId = 1;
    private String name;
    private int id;
    private String email;
    private String address;
    private String phoneNumber;
    private List<Order> orders;

    // Constructor modificado
    public Customer(String name, String email, String address, String phoneNumber) {
        this.name = name;
        this.id = generateNextId();
        this.email = email;
        this.address = address;
        this.phoneNumber = phoneNumber;
    }

    // Método para generar IDs de manera incremental
    private static synchronized int generateNextId() {
        return nextId++;
    }

    @Override
    public String toString() {
        StringBuilder ordersDetails = new StringBuilder();
        if (orders != null) {
            for (Order order : orders) {
                ordersDetails.append(order).append("\n");
            }
        }
        return "Customer{" +
                "name='" + name + '\'' +
                ", id=" + id +
                ", email='" + email + '\'' +
                ", address='" + address + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                ", orders=\n" + ordersDetails +
                '}';
    }
    public List<Order> getOrders() {
    return orders;
    }

    public void setOrders(List<Order> orders) {
    this.orders = orders;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public String getEmail() {
        return email;
    }

    public String getAddress() {
        return address;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }
}