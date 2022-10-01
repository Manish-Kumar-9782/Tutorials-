
const addbook_button = document.getElementById("addbook")
const showbooks_button = document.getElementById("showbooks")
const updatebook_button = document.getElementById("updatebook")
const deletebook_button = document.getElementById("deletebook")


const addbook_container = document.getElementById("LibManagement");
const showbooks_container = document.getElementById("showdatabase");

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

    static getBookKeys() {
        return ["primarykey", "title", "author", "subject", "pages", "price"]
    }

};

new Book("JavaScript", "Suraj420", "How not to learn JavaScript", 1203, 40);
new Book("HTML", "Gotam", "Fast way to learn HTML", 200, 150);
new Book("Anything", "Narandera", "How to learn anything", 500, 120);


class Database {

    static showdatabase_thead = null;
    static showdatabase_tbody = null;



    static load_head() {

        Database.showdatabase_thead = document.getElementById("showdatabase-thead")


        const keys = Book.getBookKeys();

        // first we need to make the table row for content of column headings.
        const tr_element = document.createElement("tr");

        for (let i = 0; i < keys.length; i++) {

            // 1. we need to create th element for each key
            let th_element = document.createElement("th")

            // 2. put the content as the key string inside the th element
            th_element.innerText = keys[i];

            // 3. append each th element into tr_element.
            tr_element.appendChild(th_element);

        }

        Database.showdatabase_thead.appendChild(tr_element);
        return tr_element;
    }

    static load_body() {
        Database.showdatabase_tbody = document.getElementById("showdatabase-tbody");

        const books = Book.BookDataBase;

        for (let i = 0; i < books.length; i++) {

            let tr_element = document.createElement("tr");
            Database.load_table_row(tr_element, books[i]);

            Database.showdatabase_tbody.appendChild(tr_element);
        }



    }

    static load_table_row(tr_element, book) {

        let keys = Book.getBookKeys();

        for (let i = 0; i < keys.length; i++) {

            let th_element = document.createElement("th");

            th_element.innerText = book[keys[i]];

            tr_element.appendChild(th_element);
        }

    }

}

Database.load_head();
Database.load_body();

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

function addBook() {
    console.log("add book button is pressed");
}

function showBooks() {
    console.log("show books button is pressed.");

    // display:none; to hide.
    // display:block: to show.

    // element.style.display = value;

    addbook_container.style.display = "none";
    showbooks_container.style.display = 'block';


}

// binding the onclick event

addbook_button.onclick = addBook;
showbooks_button.onclick = showBooks;