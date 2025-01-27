package ec.edu.espe.q61_70.view;

/**
 *
 * @author Alan Arias
 */
import ec.edu.espe.q61_70.model.Vehicle;
import java.util.List;

public class VehicleView {
    public void displayVehicleDetails(Vehicle vehicle) {
        System.out.println("Vehicle Details: " + vehicle);
    }

    public void displayVehicleList(List<Vehicle> vehicles) {
        System.out.println("Vehicle List:");
        for (Vehicle vehicle : vehicles) {
            System.out.println(vehicle);
        }
    }

    public Vehicle getVehicleInput() {
        return new Vehicle(1, "Sample Vehicle", 25000.0f, 50000.0f);
    }
}