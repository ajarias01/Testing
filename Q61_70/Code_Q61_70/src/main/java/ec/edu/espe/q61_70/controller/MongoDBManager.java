package ec.edu.espe.q61_70.controller;

/**
 *
 * @author Alan Arias
 */
import com.mongodb.ConnectionString;
import com.mongodb.MongoClientSettings;
import com.mongodb.MongoException;
import com.mongodb.ServerApi;
import com.mongodb.ServerApiVersion;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoDatabase;
import static com.mongodb.client.model.Filters.eq;
import ec.edu.espe.q61_70.model.Vehicle;
import org.bson.Document;

public class MongoDBManager {
    private static MongoClient createMongoClient() {
        String connectionString = "mongodb+srv://ajarias:ajarias@cluster0.8efem.mongodb.net/?retryWrites=true&w=majority";
        ServerApi serverApi = ServerApi.builder()
                .version(ServerApiVersion.V1)
                .build();
        MongoClientSettings settings = MongoClientSettings.builder()
                .applyConnectionString(new ConnectionString(connectionString))
                .serverApi(serverApi)
                .build();
        return MongoClients.create(settings);
    }

    public static void uploadVehicleData(int id, String name, double price, double distanceTraveled) {
        try (MongoClient mongoClient = createMongoClient()) {
            MongoDatabase database = mongoClient.getDatabase("Q61_70");
            double totalPrice = price + (distanceTraveled * 0.1);
            double approximatedMileage = distanceTraveled * 1.1;
            
            saveVehicleToDatabase(id, name, price, distanceTraveled, totalPrice, approximatedMileage, database);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

     private static void saveVehicleToDatabase(int id, String name, double price, 
            double distanceTraveled, double totalPrice, double approximatedMileage, 
            MongoDatabase database) {
        MongoCollection<Document> collection = database.getCollection("Vehicles");
        Document vehicleDocument = new Document("id", id)
                .append("name", name)
                .append("price", price)
                .append("distanceTraveled", distanceTraveled)
                .append("totalPrice", totalPrice)
                .append("approximatedMileage", approximatedMileage);
        try {
            collection.insertOne(vehicleDocument);
            System.out.println("Vehicle data saved successfully!");
        } catch (MongoException e) {
            e.printStackTrace();
        }
    }

    public static Vehicle findVehicleById(int id) {
        try (MongoClient mongoClient = createMongoClient()) {
            MongoDatabase database = mongoClient.getDatabase("Q61_70");
            MongoCollection<Document> collection = database.getCollection("Vehicles");
            Document document = collection.find(eq("id", id)).first();
            
            if (document != null) {
                int vehicleId = document.getInteger("id");
                String name = document.getString("name");
                double price = document.getDouble("price");
                double distanceTraveled = document.getDouble("distanceTraveled");
                double totalPrice = document.getDouble("totalPrice");
                double approximatedMileage = document.getDouble("approximatedMileage");
                
                return new Vehicle(vehicleId, name, (float) price, distanceTraveled, 
                                 totalPrice, approximatedMileage);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}