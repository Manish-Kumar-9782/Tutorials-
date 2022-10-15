package LibManage;

public class Book {
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
