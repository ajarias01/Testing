package espe.edu.ec.model;

import java.util.Map;

public class Cashier {
    private Customer customer;
    private float totalToPay;

    public Cashier(Customer customer) {
        this.customer = customer;
        this.totalToPay = 0;
    }

    public void calculateTotal(Map<String, Integer> order, Map<String, Float> menuItems) {
        for (Map.Entry<String, Integer> entry : order.entrySet()) {
            String dishName = entry.getKey();
            int quantity = entry.getValue();
            Float price = menuItems.get(dishName);
            if (price != null) {
                totalToPay += price * quantity;
            }
        }
    }
    public void updateInventory(Map<String, Integer> order, Map<String, Integer> inventory) {
    for (Map.Entry<String, Integer> entry : order.entrySet()) {
        String item = entry.getKey();
        int quantity = entry.getValue();
        if (inventory.containsKey(item)) {
            inventory.put(item, inventory.get(item) - quantity);
        }
    }
}

    public float getTotalToPay() {
        return totalToPay;
    }

    public Customer getCustomer() {
        return customer;
    }
}