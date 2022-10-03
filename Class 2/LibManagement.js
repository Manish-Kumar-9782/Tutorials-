
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
            Database.load_table_row(tr_element, books[i], true, true);

            Database.showdatabase_tbody.appendChild(tr_element);
        }



    }

    static load_table_row(tr_element, book, _update_ = false, _delete_ = false) {

        let keys = Book.getBookKeys();

        for (let i = 0; i < keys.length; i++) {

            let th_element = document.createElement("th");

            th_element.innerText = book[keys[i]];

            tr_element.appendChild(th_element);
        }

        if (_update_) {

            // let tdata = document.createElement("td");
            // let bt = document.createElement("button");
            // bt.setAttribute("PK", book["primarykey"]);
            // bt.innerText = "edit";
            // tdata.appendChild(bt);
            // tr_element.appendChild(tdata);

            // // binding functionality with edit  buttons
            // bt.onclick = (ev) => {
            //     // console.log(ev);
            //     console.log(Database.#getItem(book["primarykey"]));
            // }

            Database.#update("edit", book, tr_element);
        }

        if (_delete_) {
            // let tdata = document.createElement("td");
            // let bt = document.createElement("button");
            // bt.setAttribute("PK", book["primarykey"]);
            // bt.innerText = "delete";
            // tdata.appendChild(bt);
            // tr_element.appendChild(tdata);

            // binding functionality with delete button
            Database.#update("delete", book, tr_element);
        }

    }

    static #update(type, book, tr_element) {

        let tdata = document.createElement("td");

        tr_element.appendChild(tdata);

        // binding functionality with edit  buttons


        if (type == "delete") {
            let bt1 = document.createElement("button");
            bt1.setAttribute("PK", book["primarykey"]);
            bt1.innerText = type;
            tdata.appendChild(bt1);

            bt1.onclick = (ev) => {
                tr_element.remove();
                const bk_index = Book.BookDataBase.indexOf(book);
                Book.BookDataBase.splice(bk_index, 1);
            }
        }

        if (type == "edit") {
            let bt2 = document.createElement("button");
            bt2.setAttribute("PK", book["primarykey"]);
            bt2.innerText = type;
            tdata.appendChild(bt2);

        }

    }



    static #getItem(id) {
        console.log("id: ", id);

        let item = Book.BookDataBase.filter((bk) => {
            // console.log(bk)
            if (bk["primarykey"] == id) {
                return true
            }
            else {
                return false
            }
        });

        return item[0];
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

    addbook_container.style.display = "block";
    showbooks_container.style.display = "none";
}

function showBooks() {
    console.log("show books button is pressed.");

    // display:none; to hide.
    // display:block: to show.

    // element.style.display = value;

    addbook_container.style.display = "none";
    showbooks_container.style.display = "block";


}


// binding the onclick event

addbook_button.onclick = addBook;
showbooks_button.onclick = showBooks;