
class Book {

    static BookDataBase = [];
    static countBooks = 0;
    static PrimaryKey = 1000;

    constructor(title, author, pages, subject, price) {

        this.title = title;
        this.author = author;
        this.pages = pages;
        this.subject = subject;
        this.price = price;
        this.primarykey = Book.PrimaryKey;

        Book.BookDataBase.push(this); // inserting the Book into database.
        Book.countBooks++; // increasing the number of books.
        Book.PrimaryKey++;

    }

};


function getinputArray() {
    const form = document.forms[0];


    const book_title = form["title"].value;
    const book_author = form["author"].value;
    const book_subject = form["subject"].value;
    const book_pages = form["pages"].value;
    const book_price = form["price"].value;

    console.log([book_title, book_author, book_pages, book_subject, book_price])
    return [book_title, book_author, book_pages, book_subject, book_price];
}

function add_book() {

    let input_data = getinputArray();
    new Book(...input_data)

}