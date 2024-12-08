package espe.edu.ec.model;

import java.util.Map;

public class Counter {
    public float calculateTotal(Map<String, Integer> order) {
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
        return -1; // Not found
    }
}