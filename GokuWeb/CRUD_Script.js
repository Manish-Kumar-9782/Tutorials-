const bookForm = document.forms['book-form'];


class Book {

    static BookDatabase = []

    constructor(title, author, subject, pages, price, publisher) {
        this.title = title;
        this.author = author;
        this.subject = subject;
        this.pages = pages;
        this.price = price;
        this.publisher = publisher;

        Book.BookDatabase.push(this);
    }

}


bookForm.addEventListener('submit', function (event) {

    event.preventDefault();

    let bookTitle = bookForm["title"].value
    let bookAuthor = bookForm["author"].value
    let bookSubject = bookForm["Subject"].value
    let bookPages = bookForm["Pages"].value
    let bookPrice = bookForm["Price"].value
    let bookPublisher = bookForm["Publisher"].value

    new Book(bookTitle, bookAuthor, bookSubject,
        bookPages, bookPrice, bookPublisher);

    console.log("book is saved: ", Book.BookDatabase);
    bookForm.reset();
})