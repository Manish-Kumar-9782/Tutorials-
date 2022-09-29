
class Book {

    static countBook = 0;
    static BookDataBase = [];
    static PrimaryKey = 1000;

    constructor(title, author, subject, pages, prices) {

        this.title = title;
        this.author = author;
        this.subject = subject;
        this.pages = pages;
        this.prices = prices;
        this.primarykey = Book.PrimaryKey;

        // increasing the PrimaryKey
        Book.PrimaryKey++;

        // add book into BookDataBase;
        Book.BookDataBase.push(this);

        // Now we will increase the countBook;
        Book.countBook++;

    }


};


function createBook() {

    console.log("createBook function has been invoked");

    const form = document.forms['myform'];

    const title = form['title'].value;
    const author = form['author'].value;
    const subject = form['subject'].value;
    const pages = form['pages'].value;
    const prices = form['prices'].value;

    console.log([title, author, subject, pages, prices])

    new Book(title, author, subject, pages, prices);

}