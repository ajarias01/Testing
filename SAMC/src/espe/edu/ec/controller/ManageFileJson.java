package espe.edu.ec.controller;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.reflect.TypeToken;
import espe.edu.ec.model.Bill;
import espe.edu.ec.model.MenuItem;
import espe.edu.ec.model.SaleNote;
import espe.edu.ec.model.Customer;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;
import java.util.List;
import java.util.HashMap;
import java.util.ArrayList;

public class ManageFileJson {
    private final Gson gson;

    public ManageFileJson() {
        gson = new GsonBuilder().setPrettyPrinting().create();
    }

    public void saveBillToJson(Bill bill) {
        List<Bill> bills = new ArrayList<>();
        try (FileReader reader = new FileReader("bills.json")) {
            bills = gson.fromJson(reader, new TypeToken<List<Bill>>() {}.getType());
            if (bills == null) {
                bills = new ArrayList<>();
            }
        } catch (IOException e) {
            System.out.println("No se pudo leer el archivo bills.json, se creará uno nuevo.");
        }
         boolean clienteExistente = bills.stream()
            .anyMatch(existingBill -> existingBill.getCustomer().getName().equals(bill.getCustomer().getName()));

        // Si no existe, agregar la factura
        if (!clienteExistente) {
            bills.add(bill);
            try (FileWriter writer = new FileWriter("bills.json")) {
                gson.toJson(bills, writer);
                System.out.println("Factura guardada correctamente.");
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Ya existe una factura para este cliente.");
        }
    }


    public void saveSaleNoteToJson(SaleNote saleNote) {
        List<SaleNote> saleNotes = new ArrayList<>();

        try (FileReader reader = new FileReader("sale_notes.json")) {
            saleNotes = gson.fromJson(reader, new TypeToken<List<SaleNote>>() {}.getType());
            if (saleNotes == null) {
                saleNotes = new ArrayList<>();
            }
        } catch (IOException e) {
            System.out.println("No se pudo leer el archivo sale_notes.json, se creará uno nuevo.");
        }

        // Verificar si ya existe un cliente con el mismo nombre
        boolean clienteExistente = saleNotes.stream()
            .anyMatch(existingSaleNote -> existingSaleNote.getCustomer().getName().equals(saleNote.getCustomer().getName()));

        // Si no existe, agregar la nota de venta
        if (!clienteExistente) {
            saleNotes.add(saleNote);
            try (FileWriter writer = new FileWriter("sale_notes.json")) {
                gson.toJson(saleNotes, writer);
                System.out.println("Nota de venta guardada correctamente.");
            } catch (IOException e) {
                System.out.println("Error al guardar la nota de venta en JSON: " + e.getMessage());
            }
        } else {
            System.out.println("Ya existe una nota de venta para este cliente.");
        }
    }

    public void saveCommentToJson(String comment) {
        try (FileWriter writer = new FileWriter("comments.json", true)) {
            String json = gson.toJson(comment);
            writer.write(json + "\n");
            System.out.println("Comentario guardado en el archivo comments.json.");
        } catch (IOException e) {
            System.out.println("Error al guardar el comentario en JSON: " + e.getMessage());
        }
    }
    public Customer obtenerClientePorId(int customerId) {
        try (FileReader reader = new FileReader("bills.json")) {
            List<Bill> bills = gson.fromJson(reader, new TypeToken<List<Bill>>() {}.getType());
            if (bills != null) {
                for (Bill bill : bills) {
                    if (bill.getCustomer().getId() == customerId) {
                        return bill.getCustomer();
                    }
                }
            }
        } catch (IOException e) {
            System.out.println("Error al leer el archivo bills.json: " + e.getMessage());
        }
        return null;
    }

    public Map<String, Integer> obtenerPedidoPorCliente(int customerId) {
        try (FileReader reader = new FileReader("bills.json")) {
            List<Bill> bills = gson.fromJson(reader, new TypeToken<List<Bill>>() {}.getType());
            if (bills != null) {
                for (Bill bill : bills) {
                    if (bill.getCustomer().getId() == customerId) {
                        return bill.getOrder();
                    }
                }
            }
        } catch (IOException e) {
            System.out.println("Error al leer el archivo bills.json: " + e.getMessage());
        }
        return new HashMap<>();
    }
    public SaleNote obtenerNotaDeVentaPorCliente(int customerId) {
        try (FileReader reader = new FileReader("sale_notes.json")) {
            List<SaleNote> saleNotes = gson.fromJson(reader, new TypeToken<List<SaleNote>>() {}.getType());
            if (saleNotes != null) {
                for (SaleNote saleNote : saleNotes) {
                    if (saleNote.getCustomer().getId() == customerId) {
                        return saleNote;
                    }
                }
            }
        } catch (IOException e) {
            System.out.println("Error al leer el archivo sale_notes.json: " + e.getMessage());
        }
        return null;
    }
}