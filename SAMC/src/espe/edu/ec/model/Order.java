package espe.edu.ec.model;

import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Order {
    private int orderId;
    private int customerId;
    private String customerName;
    private List<MenuItem> orderedItems;
    private String tableNumber;
    private Date orderDate;
    private SaleNote saleNote;

    public Order(int orderId, int customerId, String customerName, List<MenuItem> orderedItems, 
             String tableNumber, Date orderDate, SaleNote saleNote) {
        this.orderId = orderId;
        this.customerId = customerId;
        this.customerName = customerName;
        this.orderedItems = orderedItems;
        this.tableNumber = tableNumber;
        this.orderDate = orderDate;
        this.saleNote = saleNote;
    }
    public Order(Map<String, Integer> items) {
    this.orderId = 0;
    this.customerId = 0;
    this.customerName = "";
    
    this.orderedItems = new ArrayList<>();
    for (Map.Entry<String, Integer> entry : items.entrySet()) {
        MenuItem item = MenuItem.getMenuItemById(getMenuItemIdByName(entry.getKey()));
        if (item != null) {
            for (int i = 0; i < entry.getValue(); i++) {
                this.orderedItems.add(item);
            }
        }
    }
    
    this.tableNumber = "";
    this.orderDate = new Date();
    this.saleNote = null;
}
    private int getMenuItemIdByName(String name) {
    for (MenuItem item : MenuItem.getMenuItems()) {
        if (item.getName().equalsIgnoreCase(name)) {
            return item.getId();
        }
    }
    return -1;
    }
    @Override
    public String toString() {
        StringBuilder itemsDetails = new StringBuilder();
        for (MenuItem item : orderedItems) {
            itemsDetails.append(item.getName()).append("\n");
        }
        return "Order{" +
                "orderId=" + orderId +
                ", customerId=" + customerId +
                ", customerName='" + customerName + '\'' +
                ", orderedItems=\n" + itemsDetails +
                ", tableNumber='" + tableNumber + '\'' +
                ", orderDate=" + orderDate +
                ", saleNote=" + saleNote +
                '}';
    }


    public Map<String, Integer> getItems() {
        Map<String, Integer> itemsMap = new HashMap<>();
        for (MenuItem item : orderedItems) {
            itemsMap.put(item.getName(), 1);
        }
        return itemsMap;
    }

    public float calculateOrderTotal() {
        float total = 0.0f;
        for (MenuItem item : orderedItems) {
            total += item.getPrice();
        }
        return total;
    }

    public int getCustomerId() {
        return customerId;
    }

    public void assignTable(String tableNumber) {
        // TODO
    }

    public boolean processPayment(String paymentMethod) {
        // TOD
        return false;
    }

    public int getOrderId() {
        return orderId;
    }

    public void setOrderId(int orderId) {
        this.orderId = orderId;
    }

    public void setCustomerId(int customerId) {
        this.customerId = customerId;
    }

    public String getCustomerName() {
        return customerName;
    }

    public void setCustomerName(String customerName) {
        this.customerName = customerName;
    }

    public List<MenuItem> getOrderedItems() {
        return orderedItems;
    }

    public void setOrderedItems(List<MenuItem> orderedItems) {
        this.orderedItems = orderedItems;
    }

    public String getTableNumber() {
        return tableNumber;
    }

    public void setTableNumber(String tableNumber) {
        this.tableNumber = tableNumber;
    }
    public Date getOrderDate() {
        return orderDate;
    }

    public void setOrderDate(Date orderDate) {
        this.orderDate = orderDate;
    }

    public SaleNote getSaleNote() {
        return saleNote;
    }

    public void setSaleNote(SaleNote saleNote) {
        this.saleNote = saleNote;
    }
}