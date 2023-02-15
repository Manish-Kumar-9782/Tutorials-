// first of we will get the list container.
const listContainer = document.getElementById('listContainer');


class InputAdd {
    /**
     * This will create a group of input element and button element, button will be connected to the
     * input element.
     */
    #parent = null;
    #input = null;
    #btn = null;
    #list = null;
    constructor(parent, list) {
        this.#parent = parent;
        this.#input = document.createElement("input");
        this.#input.type = "text";
        this.#list = list;

        // Now we will create a button element.
        this.#btn = document.createElement("button");
        this.#btn.textContent = "Add"

        // first appending the input
        this.#parent.appendChild(this.#input);
        this.#parent.appendChild(this.#btn);

        this.#btn.addEventListener("click", () => this.handleAddClick())
        this.#input.addEventListener("keypress", (e) => this.handleInputEnter(e))
    }

    handleAddClick() {
        // first we will get the text
        let text = this.getText();

        // now we will list item.
        this.#list.addItem(text);

        // Now making our input empty
        this.putText("");
    }

    handleInputEnter(e) {
        if (e.key === "Enter") {
            this.handleAddClick();
        }
    }

    // a function to get Text message from input
    getText() {
        return this.#input.value;
    }

    // a function to set text on input element.
    putText(content) {
        this.#input.value = content;
    }
}


class List {
    // now we will make some private properties to hold the data of list.
    #parent = null;
    #list = null;
    #listType = null;
    #input = null;
    constructor(parent, type = "ul") {
        // fist assign the parent.
        this.#parent = parent;

        // setting the list type.
        this.#listType = type;

        // Now we will create an ul list
        this.#list = document.createElement(this.#listType);

        // just before appending the list we will create an InputAdd element
        this.#input = new InputAdd(this.#parent, this)

        // Now we will append this list element into the parent element.
        this.#parent.appendChild(this.#list);
    }

    addItem(content) {
        // now we will create a new <li> element.
        let li = document.createElement("li");
        li.textContent = content;

        // Now appending this <li> element into the current list.
        this.#list.appendChild(li);
    }


}


// Creating a new list.
let myList = new List(listContainer);

myList.addItem("This is item 1")
myList.addItem("This is item 2")
myList.addItem("This is item 3")
myList.addItem("This is item 4")