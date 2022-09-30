
// document.createElement()
// document.append()



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

            this.load_td_row(tr_element, book);

            // putting the ta
            this.showDatabase_tableBody.appendChild(tr_element);
        }

    }

    load_td_row(tr_element, book_data) {
        keys = Book.getBookKeys();
        for (let i = 0; i < keys.length; i++) {

            // creating td element for each key
            let td = document.createElement("td");

            // inserting the Book keys values into the td element

            td.innerText = book_data[keys[i]];

            // putting the each td element into the table body row.
            tr_element.appendChild(td);
        }

        return tr_element;
    }
}







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