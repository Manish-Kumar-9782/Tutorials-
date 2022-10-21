import java.util.Scanner;

class Display {

    static private char escCode = 0x1B;
    static private int lineNumber = 0;

    static void printSeprator(int num) {
        for (int i = 0; i < num; i++) {
            System.out.print("-");
        }
        System.out.print("\n");
    }

    static void println(String msg) {
        System.out.println(msg);
    }

    static void print(String msg) {
        System.out.print(msg);
    }

}

class Book {

    String title;
    String author;
    int pages;
    int price;
    String publisher;
    String department;
    int primary_key;
    static int bookCount;
    static Book BookDatabase[];
    static int primaryKey;

    static {
        bookCount = 0;
        BookDatabase = new Book[10];
        primaryKey = 1000;
    }

    Book(String title, String author, int pages, int price, String publisher, String department) {
        this.primary_key = Book.primaryKey;
        this.title = title;
        this.author = author;
        this.pages = pages;
        this.price = price;
        this.publisher = publisher;
        this.department = department;

        // Now we will add and increase the book
        Book.BookDatabase[Book.bookCount++] = this;
        Book.primaryKey++;
    }
}

public class LibManagement {

    static void showOptions() {
        Display.println("1. Add a Book");
        Display.println("2. Delete a Book");
        Display.println("3. Issue a Book");
        Display.println("4. Return a Book");
        Display.println("5. Show Library Database");
        Display.println("\n\n\n\n");
    }

    static void addBook() {
        // here first we will scan the Book data then we will create a new instance of
        // the book
        Display.println("adding a book");
    }

    static void deleteBook() {
        Display.println("deleting a book");
    }

    static void issueBook() {
        Display.println("issue a book");
    }

    static void returnBook() {
        Display.println("return a book");
    }

    static void showBooks() {
        Display.println("showing book database");
    }

    public static void main(String[] args) {
        System.out.println(String.format("%30s %s", " ", "Welcome To Library Management"));
        Display.printSeprator(100);

        // Now we need to make the switch statement which will run all the selected
        // option
        showOptions();
        Display.print("Select an option:\t");
        Scanner scan = new Scanner(System.in);
        int key;
        key = scan.nextInt();

        switch (key) {
            case 1:
                // here we will add the book
                break;
            case 2:
                // here we will delete the book
                break;
            case 3:
                // here we will issue a book
                break;
            case 4:
                // here we will return a book
                break;

            case 5:
                // here we will show the data base.
                break;

            default:
                break;
        }
    }
}
