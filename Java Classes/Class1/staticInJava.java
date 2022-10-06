
/*
 * 1. only one public class can exist in one java file.
 * 2. if we want to run the current file program then we must have the main 
 *  function in our public class.
 * 
 * static:
 *  -> Data member will not be bound with the class object, it will be bound
 *  directly to the class itself. 
 * 
 * -> it means we have to access static data member or static method with the 
 * class name. (ClassName.Static_Member)
 * 
 * -> all static data members and method loads during the class loading. 
 *  (compile time loading.)
 * 
 * -> all static members only initialized only once during the compilation inside
 *  the class scope, and all static member will be shared to all the class object 
 * by using the common memory address.
 * 
 * []: square brackets
 * {}: curly brackets
 * (): parenthesis
 * 
 * private, protected, public, default
 */

class Book {

    // data members by default they have access modifier as default
    /*
     * static members
     * -> bookCount: to count the book.
     * -> primaryKey: a unique key for each book.
     * -> bookDatabase: to store all the books in an array.
     * 
     * Book object data members.
     * title, author, subject, pages, price
     */

    static int bookCount;
    static int primaryKey;
    static Book bookDatabase[];

    // instance data members.
    String title;
    String author;
    String subject;
    int pages;
    int primarykey;
    double price;

    static {
        bookCount = 0;
        primaryKey = 1000;
        bookDatabase = new Book[10];
    }

    Book(String title, String author, String subject, int pages, double price) {
        this.title = title;
        this.author = author;
        this.subject = subject;
        this.pages = pages;
        this.price = price;
        this.primarykey = Book.primaryKey;

        // update our bookCount, primaryKey, bookDatabase.
        Book.bookDatabase[Book.bookCount++] = this;
        System.out.println("book count: " + Book.bookCount);
        Book.primaryKey++;
    }

    void display() {
        System.out.println("Primary Key: \t\t" + this.primarykey);
        System.out.println("Title: \t\t" + this.title);
        System.out.println("Author: \t\t" + this.author);
        System.out.println("Subject: \t\t" + this.subject);
        System.out.println("Pages: \t\t" + this.pages);
        System.out.println("Price: \t\t" + this.price);
    }

    void inline_display() {
        System.out.println(this.primarykey + "\t" + this.title + "\t" + this.author + "\t" + this.subject + "\t"
                + this.pages + "\t" + this.price);
    }

    static void book_headings() {
        System.out.println("primarykey" + "\t" + "title" + "\t" + "author" + "\t" + "subject" + "\t"
                + "pages" + "\t" + "price");
    }

    static void showDatabase() {
        Book.book_headings();

        for (int i = 0; i < Book.bookCount; i++) {
            Book.bookDatabase[i].inline_display();
        }
    }
}

public class staticInJava {

    public static void main(String[] args) {
        new Book("Java", "Saloni", "Master in Java", 200, 120);
        new Book("C++", "Komal", "C++ for Dummies", 200, 96);
        new Book("C", "Abhishek", "Primary C", 160, 80);

        System.out.println("\n----------------------------------------------------\n");
        Book.showDatabase();
        System.out.println("\n----------------------------------------------------\n");
    }
}
