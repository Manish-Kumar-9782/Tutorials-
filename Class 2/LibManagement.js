
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
    const inputArray = form.getElementsByTagName("input");

    console.log(inputArray);

    return inputArray;
}

function add_book() {

    const form = document.forms[0];

    const inputArray = form.getElementsByTagName("input");



}