import java.util.Scanner;

//=============================================================================//
class Display {

    static void printSep(int len) {
        for (int i = 0; i < len; i++) {
            System.out.print("-");
        }
        System.out.print("\n");
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

    static void showOptions() {

        System.out.println("1. Add Book");
        System.out.println("2. Remove Book");
        System.out.println("3. Issue Book");
        System.out.println("4. Return Book");
        System.out.println("5. Show Books");
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
                showOptions();
                getOptions();
                break;
            case 2:
                // remove a book
                System.out.println("remove a book");

                showOptions();
                getOptions();
                break;
            case 3:
                // issue a book
                System.out.println("issue a book");

                showOptions();
                getOptions();
                break;
            case 4:
                // return a book
                System.out.println("return a book");

                showOptions();
                getOptions();
                break;
            case 5:
                // show a book
                System.out.println("show books");
                showDatabase();
                showOptions();
                getOptions();
                break;
            default:
                // invalid option
                System.out.println("adding a book");
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

        String cmd;

        Display.printSep(100);
        System.out.println("\n\n\n\n");
        System.out.println(String.format("%35s %s", " ", "Welcome To LibManagement"));
        Display.printSep(100);
        System.out.println("");
        showOptions();

        do {
            Scanner scan = new Scanner(System.in);
            getOptions();

            cmd = scan.next();
        } while (cmd != "quit");
    }
}

// =============================================================================//