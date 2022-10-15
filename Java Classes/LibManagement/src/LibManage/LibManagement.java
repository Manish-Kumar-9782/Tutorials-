package LibManage;

import java.util.Scanner;

public class LibManagement {
    static void addPreBooks() {
        new Book("java", "komal", "wiley", 234, 120, "IT");
        new Book("HTML", "Abhishek", "Pearson", 342, 234, "IT");
        new Book("C++", "Saloni", "Pearson", 2345, 432, "IT");
        new Book("IC Engine", "Manish", "Spring", 122, 123, "Mechanical");
    }

    static void addPersons(){
        Address adrs = new Address(20, "sitapura", "sitapura",
                "sitapura", "jaipur", "jaipur", "rajasthan",
                "india", 302022);

        Registration.registrations[Registration.countPerson++] = new Person("Komal", 21, 5.7,adrs);
        Registration.registrations[Registration.countPerson++] = new Person("Saloni", 21, 5.6,adrs);
    }

    static void showMainHead() {
        Display.clScreen();
        Display.printSep(120);
        System.out.println("\n\n\n\n");
        System.out.println(String.format("%35s %s", " ", "Welcome To LibManagement"));
        Display.printSep(120);
        System.out.println("");
    }

    static void showOptions() {

        System.out.println("1. Add Book");
        System.out.println("2. Remove Book");
        System.out.println("3. Issue Book");
        System.out.println("4. Return Book");
        System.out.println("5. Show Books");
        System.out.println("6.Other");
    }

    static void showOtherOptions(){
        Display.clScreen();
        Display.sectionHeading("Other Options");
        Display.printSep(100);
        System.out.println("1. Add Person");
        System.out.println("2. Show Persons");
    }

    static void showRegisteredPerson(){
        Display.clScreen();
        Display.sectionHeading("Registered Person");
        Display.printSep(100);

        Person.showHeading();
        Display.printSep(100);

        for (int i=0; i<Registration.countPerson; i++){
            Registration.registrations[i].inline_display();
        }
    }
    static void getOtherOptions(){
        Scanner scan = new Scanner(System.in);
        int option = scan.nextInt();

        switch (option){
            case 1:
                Registration.registerPerson();
                break;

            case 2:
                showRegisteredPerson();
                break;
            default:
                break;

        }
    }
    // ----------------------------------------------------------------------//

    static void getOptions() {
        // Now we need to take input the selection
        Scanner scan = new Scanner(System.in);

        // now we need to scan input as integer
        int selection = scan.nextInt();

        switch (selection) {
            case 1:
                // add a book
                System.out.println("add a book");
                addBook();
                System.out.println("A Book is added");

                break;
            case 2:
                // remove a book
                System.out.println("remove a book");
                break;
            case 3:
                // issue a book
                System.out.println("issue a book");
                break;
            case 4:
                // return a book
                System.out.println("return a book");
                break;
            case 5:
                // show a book
                System.out.println("show books");
                showDatabase();
                break;

            case 6:
                // other section (registerPerson)
                showOtherOptions();
                getOtherOptions();
                break;
            default:
                // invalid option
                System.out.println("Invalid Option");
                break;
        }

    }

    // ----------------------------------------------------------------------//
    static void addBook() {
        Scanner scan = new Scanner(System.in);

        System.out.print("Book Title: ");
        String title = scan.nextLine();

        System.out.print("Book Author: ");
        String author = scan.nextLine();

        System.out.print("Book Publisher: ");
        String publisher = scan.nextLine();

        System.out.print("Book Department: ");
        String dept = scan.nextLine();

        System.out.print("Book Pages: ");
        int pages = scan.nextInt();

        System.out.print("Book Price: ");
        double price = scan.nextInt();

        new Book(title, author, publisher, pages, price, dept);
    }

    // ----------------------------------------------------------------------//

    static void showDatabase() {
        System.out.println("Book Database");
        Book.getHeader();
        Display.printSep(100);

        for (int i = 0; i < Book.countBooks; i++) {
            Book.bookDatabase[i].inline_display();
        }
    }

    // ----------------------------------------------------------------------//

    public static void main(String[] args) {
        addPreBooks();
        addPersons();
        String cmd;
        Scanner scan = new Scanner(System.in);

        do {
            showMainHead();
            showOptions();
            getOptions();

            System.out.println("Press any key: ");
            cmd = scan.nextLine();

            if (cmd.equals("quit")) {
                break;
            }
        } while (true);
    }
}
