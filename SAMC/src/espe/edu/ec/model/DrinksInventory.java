package espe.edu.ec.model;
/**
 * Clase que representa el inventario de bebidas
 * 
 * @author Camila Bohorquez
 */
public class DrinksInventory {
    private int idInventory;
    private String nameDrinks;
    private String addressOfDescription;
    private float price;
    private boolean isAvailable;
    private int quantity;
    
    @Override
    public String toString() {
        return "DrinksInventory{" +
                "idInventory=" + idInventory +
                ", nameDrinks='" + nameDrinks + '\'' +
                ", addressOfDescription='" + addressOfDescription + '\'' +
                ", price=" + price +
                ", isAvailable=" + isAvailable +
                '}';
    }

    
    public DrinksInventory() {
    }

    
    public DrinksInventory(int idInventory, String nameDrinks, String addressOfDescription, float price, boolean isAvailable) {
        this.idInventory = idInventory;
        this.nameDrinks = nameDrinks;
        this.addressOfDescription = addressOfDescription;
        this.price = price;
        this.isAvailable = isAvailable;
    }

    
    public int getIdInventory() {
        return idInventory;
    }

    public void setIdInventory(int idInventory) {
        this.idInventory = idInventory;
    }

    public String getNameDrinks() {
        return nameDrinks;
    }

    public void setNameDrinks(String nameDrinks) {
        this.nameDrinks = nameDrinks;
    }

    public String getAddressOfDescription() {
        return addressOfDescription;
    }

    public void setAddressOfDescription(String addressOfDescription) {
        this.addressOfDescription = addressOfDescription;
    }

    public float getPrice() {
        return price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void setAvailable(boolean isAvailable) {
        this.isAvailable = isAvailable;
    }
    public void reduceInventory(int quantity) {
    if (isAvailable && quantity > 0) {
        isAvailable = isAvailable && quantity <= this.quantity;
        this.quantity -= quantity;
    } else {
        System.out.println("No hay suficiente stock.");
    }
}
}