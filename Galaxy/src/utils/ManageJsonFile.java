package utils;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import ec.edu.espe.galaxy.model.Galaxy;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 
 * @author Alan
 */
public class ManageJsonFile {
    private static final List<Galaxy> galaxys = new ArrayList<>();
    private static final String FILE_PATH = "galaxys.json";
    private static final Gson gson = new Gson();
    
    public static void createGalaxy(Scanner scanner) {       
        System.out.println("Alan's Save Galaxy Simulator ");
        System.out.println("Enter the Data of the Galaxy");
       
        System.out.println("ID: ");
        int id = scanner.nextInt();
        scanner.nextLine();
        
        System.out.println("name: ");
        String name = scanner.nextLine();
        
        System.out.println("type (spiral, elliptical, irregular): ");
        String type = scanner.nextLine();
        
        System.out.println("number of stars: ");
        int numberOfStars = scanner.nextInt();
        scanner.nextLine();
        
        Galaxy galaxy = new Galaxy(id, name, type, numberOfStars);
        galaxys.add(galaxy);
        saveGalaxyToJSON();
        System.out.println("Galaxy Successfully added");
    }
    
    public static void readGalaxy() {
        loadGalaxyFromJSON();

        if (galaxys.isEmpty()) {
            System.out.println("No galaxys found.");
        } else {
            for (Galaxy galaxy : galaxys) {
                System.out.println(galaxy);
            }
        }
    }
    
    private static void saveGalaxyToJSON() {
        try (FileWriter writer = new FileWriter(FILE_PATH)) {
            gson.toJson(galaxys, writer);
        } catch (IOException e) {
            System.err.println("Error saving galaxy to JSON: " + e.getMessage());
        }
    }
    
    private static void loadGalaxyFromJSON() {
        try (FileReader reader = new FileReader(FILE_PATH)) {
            Type listType = new TypeToken<ArrayList<Galaxy>>(){}.getType();
            List<Galaxy> loadedGalaxys = gson.fromJson(reader, listType);
            galaxys.clear();
            galaxys.addAll(loadedGalaxys);
        } catch (IOException e) {
            System.err.println("Error loading galaxys from JSON: " + e.getMessage());
        }
    }
}