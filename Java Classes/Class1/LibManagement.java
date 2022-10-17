import java.util.Scanner;

//=============================================================================//
class Display {

    static void printSep(int len) {
        for (int i = 0; i < len; i++) {
            System.out.print("-");
        }
        System.out.print("\n");
    }

    static void clScreen() {
        /*
         * ANSI Code
         * \033[H: It moves the cursor at the top left corner of the screen or console.
         * \033[2J: It clears the screen from the cursor to the end of the screen.
         */
        System.out.print("\033[H\033[2J");
        System.out.flush(); // to reset the cursor position at the top of the console screen
    }
}

// =============================================================================//

class Book {

    String title, author, publisher, department;
    int pages, pk;
    double price;

    static String tableFormat = "%-20s %-20s %-15s %-20s %-8s %-8s %-20s";
    static int countBooks;
    static Book bookDatabase[];
    static int primaryKey;

    static {
        countBooks = 0;
        bookDatabase = new Book[10];
        primaryKey = 1000;
    }

    Book(String title, String author, String publisher, int pages, double price, String department) {

        this.title = title;
        this.author = author;
        this.publisher = publisher;
        this.pages = pages;
        this.price = price;
        this.department = department;
        this.pk = primaryKey;

        // Now we need to update the static variable of book database.
        Book.bookDatabase[countBooks++] = this;
        Book.primaryKey++;
    }

    void inline_display() {
        // primaryKey, title, author, publisher, page, price, department
        System.out.println(
                String.format(Book.tableFormat, this.pk, this.title, this.author, this.publisher, this.pages,
                        this.price,
                        this.department));
    }

    static void getHeader() {
        System.out.println(
                String.format(Book.tableFormat, "Primary key", "Title", "Author", "Publisher", "Pages", "Price",
                        "Department"));
    }
}

// =============================================================================//

public class LibManagement {

    static void addPreBooks() {
        new Book("java", "komal", "wiley", 234, 120, "IT");
        new Book("HTML", "Abhishek", "Pearson", 342, 234, "IT");
        new Book("C++", "Saloni", "Pearson", 2345, 432, "IT");
        new Book("IC Engine", "Manish", "Spring", 122, 123, "Mechanical");
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

// =============================================================================//