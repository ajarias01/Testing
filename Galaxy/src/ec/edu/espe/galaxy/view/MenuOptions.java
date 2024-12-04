
package ec.edu.espe.galaxy.view;

import java.util.Scanner;
import static utils.ManageJsonFile.createGalaxy;
import static utils.ManageJsonFile.readGalaxy;


/**
 *
 * @author Alan
 */
public class MenuOptions {
        public static void showMenuOptions() {
        try (Scanner scanner = new Scanner(System.in)) {
            int operation;

            do {
                System.out.println("--------Menu--------");
                System.out.println("1. Create Galaxy");
                System.out.println("2. Read Data Galaxy");
                System.out.println("3. Exit");

                System.out.print("Enter the option: ");
                operation = scanner.nextInt();
                scanner.nextLine();

                switch (operation) {
                    case 1:
                        createGalaxy(scanner);
                        break;
                    case 2:
                        readGalaxy();
                        break;
                    case 3:
                        System.out.println("Exiting...");
                        break;

                    default:
                        System.out.println("Invalid operation.");
                }
            } while (operation != 3);
        }
    }
}