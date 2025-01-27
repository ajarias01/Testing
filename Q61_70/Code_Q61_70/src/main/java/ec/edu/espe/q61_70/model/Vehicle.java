

package ec.edu.espe.q61_70.model;

/**
 *
 * @author Alan Arias
 */
public class Vehicle {
    private int id;
    private String name;
    private float price;
    private double distance;
    private double totalPrice;
    private double approximatedMileage;

    public Vehicle(int id, String name, float price, double distance) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.distance = distance;
    }
    public Vehicle(int id, String name, float price, double distanceTraveled, 
                  double totalPrice, double approximatedMileage) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.distance = distanceTraveled;
        this.totalPrice = totalPrice;
        this.approximatedMileage = approximatedMileage;
    }
    /**
     * @return the id
     */
    public int getId() {
        return id;
    }

    /**
     * @param id the id to set
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return the price
     */
    public float getPrice() {
        return price;
    }

    /**
     * @param price the price to set
     */
    public void setPrice(float price) {
        this.price = price;
    }

    /**
     * @return the distance
     */
    public double getDistance() {
        return distance;
    }

    /**
     * @param distance the distance to set
     */
    public void setDistance(double distance) {
        this.distance = distance;
        this.totalPrice = this.price + (distance * 0.1);
        this.approximatedMileage = distance * 1.1;
    }

    /**
     * @return the totalPrice
     */
    public double getTotalPrice() {
        return totalPrice;
    }

    /**
     * @param totalPrice the totalPrice to set
     */
    public void setTotalPrice(double totalPrice) {
        this.totalPrice = totalPrice;
    }

    /**
     * @return the approximatedMileage
     */
    public double getApproximatedMileage() {
        return approximatedMileage;
    }

    /**
     * @param approximatedMileage the approximatedMileage to set
     */
    public void setApproximatedMileage(double approximatedMileage) {
        this.approximatedMileage = approximatedMileage;
    }
    
    
}
