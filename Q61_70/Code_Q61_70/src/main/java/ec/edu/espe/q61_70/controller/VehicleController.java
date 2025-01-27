package ec.edu.espe.q61_70.controller;

/**
 *
 * @author Alan Arias
 */
import ec.edu.espe.q61_70.model.Vehicle;
import ec.edu.espe.q61_70.view.VehicleView;
import java.util.ArrayList;
import java.util.List;

public class VehicleController {
    private List<Vehicle> vehicles;
    private VehicleView view;
    private int idCounter = 1;

    public VehicleController(VehicleView view) {
        this.vehicles = new ArrayList<>();
        this.view = view;
    }

    public void addVehicle(String name, float price, double distance) {
        Vehicle vehicle = new Vehicle(idCounter++, name, price, distance);
        vehicles.add(vehicle);
    }

    public void removeVehicle(int id) {
        vehicles.removeIf(vehicle -> vehicle.getId() == id);
    }

    public void updateVehicle(Vehicle updatedVehicle) {
        for (Vehicle vehicle : vehicles) {
            if (vehicle.getId() == updatedVehicle.getId()) {
                vehicle.setName(updatedVehicle.getName());
                vehicle.setPrice(updatedVehicle.getPrice());
                vehicle.setDistance(updatedVehicle.getDistance());
            }
        }
    }

    public Vehicle getVehicle(int id) {
        for (Vehicle vehicle : vehicles) {
            if (vehicle.getId() == id) {
                return vehicle;
            }
        }
        return null;
    }

    public void listVehicles() {
        view.displayVehicleList(vehicles);
    }

    public void showVehicleDetails(int id) {
        Vehicle vehicle = getVehicle(id);
        if (vehicle != null) {
            view.displayVehicleDetails(vehicle);
        } else {
            System.out.println("Vehicle not found");
        }
    }
}