package LibManage;

import java.util.Scanner;

public class Registration {

    static RegisteredPerson registrations[];
    static int countPerson;
    static int libId;

    static {
        registrations = new RegisteredPerson[10];
        countPerson=0;
        libId = 100;
    }

    static void registerPerson(){
//        adding a new Person into the Library Management system.
        Display.clScreen();

        System.out.println(String.format("%40s %s", " ", "Add Person"));
        Display.printSep(100);

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Person Details: \n");

        // Adding Person details
        System.out.print("Enter Person Name: ");
        String name = scan.nextLine();
        System.out.print("Enter Person Age: ");
        int age = scan.nextInt();
        System.out.print("Enter Person Height: ");
        double height = scan.nextDouble();

        // Now get the address information
        Address adrs = new Address(); // default address.
        adrs.scanAddress();

        Display.printSep(100);

        Registration.registrations[Registration.countPerson++] = new RegisteredPerson(name, age, height,adrs);
    }
}
