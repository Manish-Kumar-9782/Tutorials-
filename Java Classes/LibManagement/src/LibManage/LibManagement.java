package LibManage;

import java.util.Scanner;

public class LibManagement {
    static void addPreBooks() {
        new RegisteredBook("IT","java", "komal", "wiley", 234, 120 );
        new RegisteredBook("IT","HTML", "Abhishek", "Pearson", 342, 234);
        new RegisteredBook("IT","C++", "Saloni", "Pearson", 2345, 432);
        new RegisteredBook("Mechanical","IC Engine", "Manish", "Spring", 122, 123);
    }

    static void addPersons(){
        Address adrs = new Address(20, "sitapura", "sitapura",
                "sitapura", "jaipur", "jaipur", "rajasthan",
                "india", 302022);

        Registration.registrations[Registration.countPerson++] = new RegisteredPerson("Komal", 21, 5.7,adrs);
        Registration.registrations[Registration.countPerson++] = new RegisteredPerson("Saloni", 21, 5.6,adrs);
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
        System.out.println("7. Search Book");
        System.out.println("8. All Issued Books");
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

//        Here we need to provide an additional option to show the address of person.
    }
    static void getOtherOptions(){
        Scanner scan = new Scanner(System.in);
        int option = scan.nextInt();

        switch (option){
            case 1:
                // to add a new person
                Registration.registerPerson();
                break;

            case 2:
                // to show all the person
                showRegisteredPerson();
                break;
            default:
                break;

        }
    }
    // ----------------------------------------------------------------------//

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
//                first we need to select the book
                RegisteredBook bk = RegisteredBook.searchBook();

                if(bk != null){
                    bk.issueBook();
                }
                else{
                    System.out.println("No match found...");
                }

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

            case 7:
//                search book
                RegisteredBook bkX = RegisteredBook.searchBook();
                if(bkX != null){
                    System.out.println("match found");
                    bkX.inline_display();
                }
                else{
                    System.out.println("No Match found");
                }
                break;
            case 8:
//                all issued books
                    RegisteredBook.showDatabase();
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

        new RegisteredBook(dept, title, author, publisher, pages, price);
    }

    // ----------------------------------------------------------------------//

    static void showDatabase() {
        System.out.println("Book Database");
        RegisteredBook.getHeader();
        Display.printSep(100);

        for (int i = 0; i < RegisteredBook.countBooks; i++) {
            RegisteredBook.bookDatabase[i].inline_display();
        }
    }

    // ----------------------------------------------------------------------//


    // ----------------------------------------------------------------------//
//        Issue a Book

    static void issueBook(){
//        For now all the books are stored inside the
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
