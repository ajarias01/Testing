package espe.edu.ec.model;

/**
 *
 * @author Alan
 */
public class DishInventory {
    private int idDishInventory;
    private String nameDish;
    private String addressOfDescription;
    private float price;
    private boolean isAvailable;
    private int quantity;

    @Override
    public String toString() {
        return "DishInventory{" 
                + "idDishInventory=" + idDishInventory 
                + ", nameDish=" + nameDish 
                + ", addressOfDescription=" + addressOfDescription 
                + ", price=" + price 
                + ", isAvailable=" + isAvailable + '}';
    }
    public DishInventory() {
    }
    public DishInventory(int idDishInventory, String nameDish, String addressOfDescription, float price, boolean isAvailable) {
        this.idDishInventory = idDishInventory;
        this.nameDish = nameDish;
        this.addressOfDescription = addressOfDescription;
        this.price = price;
        this.isAvailable = isAvailable;
    }
    public int getIdDishInventory() {
        return idDishInventory;
    }

    public void setIdDishInventory(int idInventory) {
        this.idDishInventory = idDishInventory;
    }

    public String getNameDrinks() {
        return nameDish;
    }

    public void setNameDrinks(String nameDrinks) {
        this.nameDish = nameDish;
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
