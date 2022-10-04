
// document.createElement()
// document.append()

/**
 *  <button id="addBook">AddBook</button>
    <button id="showBook">ShowDatabase</button>
    <button id="updateBook">UpdateBook</button>
    <button id="deleteBook">DeleteBook</button>
 */

const addBook_button = document.getElementById("addBook");
const showBook_button = document.getElementById("showBook");
const updateBook_button = document.getElementById("updateBook");
const deleteBook_button = document.getElementById("deleteBook");

/*------------------------------------------------------------*/

const addbook_section = document.getElementById("addbook");
const showdatabase_section = document.getElementById("showdatabase")

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

    static getBookKeys() {
        return ["primarykey", "title", "author", "subject", "pages", "prices"];
    }


};

new Book("JavaScript", "Suraj420", "How not to learn JavaScript", 1203, 40);
new Book("HTML", "Gotam", "Fast way to learn HTML", 200, 150);
new Book("Anything", "Narandera", "How to learn anything", 500, 120);


class ShowDatabase {

    /**
     *  ShowDatabase will be used to show the Book database on the web page.
     * 
     *  1. first we need to load the head and body element.
     *  2. update the head with Book keys.
     *  3. update the body with Book data base.
     *  4. load the data. 
     */

    showDatabase_tableHead = null;
    showDatabase_tableBody = null;

    constructor() {
        this.showDatabase_tableHead = document.getElementById("showdatabase-thead");
        this.showDatabase_tableBody = document.getElementById("showdatabase-tbody");

        // here now we need to load the head
        this.load_head();
        this.load_body();
    }

    load_head() {
        // an empty object of the class.
        let keys = Book.getBookKeys();
        const thead_row = document.createElement("tr");
        for (let i = 0; i < keys.length; i++) {

            // 1. create the th element
            let th = document.createElement("th");

            // 2. putting the text/content inside the th element.
            th.innerText = keys[i];

            // 3. adding each th element at the end of thead_row element.
            thead_row.appendChild(th);
        }

        this.showDatabase_tableHead.appendChild(thead_row);

        return thead_row;
    }

    load_body() {

        // create row element for each book

        for (let i = 0; i < Book.BookDataBase.length; i++) {

            // create tr_element for each book
            let tr_element = document.createElement("tr");

            // get book one by one using i.
            let book = Book.BookDataBase[i];

            // Now we need to load the data inside the tr element
            this.load_td_row(tr_element, book, true, true);

            // putting the ta
            this.showDatabase_tableBody.appendChild(tr_element);
        }

    }

    load_td_row(tr_element, book_data, _update_ = false, _delete_ = false) {
        let keys = Book.getBookKeys();
        for (let i = 0; i < keys.length; i++) {

            // creating td element for each key
            let td = document.createElement("td");

            // inserting the Book keys values into the td element

            td.innerText = book_data[keys[i]];

            // putting the each td element into the table body row.
            tr_element.appendChild(td);
        }

        if (_update_) {
            let td = document.createElement("td");
            let bt = document.createElement("button");
            bt.setAttribute("PK", book_data["primarykey"]);


            bt.onclick = (event) => {
                let id = book_data["primarykey"];
                ShowDatabase.#edit(id, tr_element, book_data);
                console.log(id, tr_element);
            };



            bt.innerText = "edit";
            td.appendChild(bt);
            tr_element.appendChild(td);
        }

        if (_delete_) {
            // creating another td for update button 
            // this td will be placed inside the tr_element.
            let td = document.createElement("td");
            let bt = document.createElement("button");
            bt.setAttribute("PK", book_data["primarykey"]);
            bt.innerText = "delete";
            td.appendChild(bt);
            tr_element.appendChild(td);
        }


        return tr_element;
    }

    display_database() {

        //this function will hide other sections and only make the Database visible.
        // hide-> display:none;
        // show -> display:block;

        // first we have to hide the addbook_section.
        addbook_section.style.display = "none";
        // after hiding the addbook_section we need to show the showdatabase_section.
        showdatabase_section.style.display = "block";
    }

    static #edit(id, element, bookdata) {

        ShowDatabase.#getdata_from_html(element);

    }

    static #getdata_from_html(tr_element) {


        // we have the total number 
        let tds = tr_element.getElementsByTagName("td")


        addbook_section["title"].value = tds[1].innerText
        addbook_section["author"].value = tds[2].innerText
        addbook_section["subject"].value = tds[3].innerText
        addbook_section["pages"].value = tds[4].innerText
        addbook_section["prices"].value = tds[5].innerText

        addbook_section.style.display = "block";
        showdatabase_section.style.display = "none";

    }


    /**====================================================================*/

    addbook_function() {
        //this function will hide other sections and only make the Database visible.
        // hide-> display:none;
        // show -> display:block;
        addbook_section.style.display = "block";
        showdatabase_section.style.display = "none";
    }

    update_function() {



    }

}

const database = new ShowDatabase();

// Now here we need to bind our showBook_button.onclick event with the database.display_database.

showBook_button.onclick = database.display_database;
addBook_button.onclick = database.addbook_function;


function createBook() {

    console.log("createBook function has been invoked");

    const form = document.forms['addbook'];

    const title = form['title'].value;
    const author = form['author'].value;
    const subject = form['subject'].value;
    const pages = form['pages'].value;
    const prices = form['prices'].value;

    console.log([title, author, subject, pages, prices])

    new Book(title, author, subject, pages, prices);

}


/*
    Process of editing data.
    
    1. get the data from HTML elements
    2. get the Book instance with the matching primarykey
    3. go back to add book form put all the currently selected element.
    4. we need to make getdata to retrieve data from HTML element
    5. we need to make putdata to put the data into the form element.
    6. we also need to make a function to update the database.



*/