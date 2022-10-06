
const addbook_button = document.getElementById("addbook")
const showbooks_button = document.getElementById("showbooks")
const updatebook_button = document.getElementById("updatebook")
const deletebook_button = document.getElementById("deletebook")


const addbook_container = document.getElementById("LibManagement");
const showbooks_container = document.getElementById("showdatabase");


const createBook_button = document.getElementById("cbook");
const saveEdit_button = document.getElementById("ebook");

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

            let td_element = document.createElement("td");

            td_element.innerText = book[keys[i]];

            tr_element.appendChild(td_element);
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
            // first we will create a button
            let bt1 = document.createElement("button");
            // now we need to set the attribute id  as the primary key.
            bt1.setAttribute("PK", book["primarykey"]);
            // now we will put the inner text of the button
            bt1.innerText = type;
            // appending (adding at the last position )
            tdata.appendChild(bt1);


            //=================================================//
            // event for delete functionality
            bt1.onclick = (ev) => {
                // removing the selected element
                tr_element.remove();
                const bk_index = Book.BookDataBase.indexOf(book);
                Book.BookDataBase.splice(bk_index, 1);
            }
            //=================================================//
        }

        if (type == "edit") {
            let bt2 = document.createElement("button");
            bt2.setAttribute("PK", book["primarykey"]);
            bt2.innerText = type;
            tdata.appendChild(bt2);

            /*
                1. get data from HTML Element
                2. put HTML data to form
                3. switch to form and edit the data.
                4. save the changes.
                5. changes should be also made in the book object 
                    form database.
            */

            //=================================================//
            bt2.onclick = (ev) => {

                Database.#get_data_from_html(tr_element, book);
            }
            //=================================================//
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


    static #get_data_from_html(tr_element, book) {

        let tds = tr_element.getElementsByTagName("td");
        console.log(tds);

        addbook_container["title"].value = tds[1].innerText
        addbook_container["author"].value = tds[2].innerText
        addbook_container["subject"].value = tds[3].innerText
        addbook_container["pages"].value = tds[4].innerText
        addbook_container["price"].value = tds[5].innerText

        // 3. switching to the form
        addbook_container.style.display = "block";  // show
        showbooks_container.style.display = "none"; // hide

        // first hide the creatBook_button
        // then we need to display the saveEdit_button

        createBook_button.style.display = "none";
        saveEdit_button.style.display = "block";

        saveEdit_button.onclick = (ev) => {

            Database.#saveEdit_Changes(book, tr_element);
        }

    }


    static #saveEdit_Changes(book, tr_element) {

        book["title"] = addbook_container["title"].value
        book["author"] = addbook_container["author"].value
        book["subject"] = addbook_container["subject"].value
        book["pages"] = addbook_container["pages"].value
        book["price"] = addbook_container["price"].value


        // 3. switching to the form
        addbook_container.style.display = "none";  // show
        showbooks_container.style.display = "block"; // hide

        // first hide the creatBook_button
        // then we need to display the saveEdit_button

        createBook_button.style.display = "block";
        saveEdit_button.style.display = "none";

        let tds = tr_element.getElementsByTagName("td");
        console.log(tds);

        // updating the html tr -> td elements
        tds[1].innerText = addbook_container["title"].value
        tds[2].innerText = addbook_container["author"].value
        tds[3].innerText = addbook_container["subject"].value
        tds[4].innerText = addbook_container["pages"].value
        tds[5].innerText = addbook_container["price"].value

        // resetting the form container
        addbook_container.reset()
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