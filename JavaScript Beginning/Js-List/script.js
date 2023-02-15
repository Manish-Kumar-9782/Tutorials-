
// first of all we will get the list Container.

const listContainer = document.getElementById('listContainer');

// Now after getting this list container will make a class to create the list blocks.

class InputAdd {
    /*
        This will create an input element with add button.
    */

    #input = null;
    #btnAdd = null;
    #divContainer = null;
    #parentContainer = null;

    constructor(parentContainer, list) {
        this.#parentContainer = parentContainer;

        // Now we will create a div element in which we will put our input element
        // and button element.

        this.#divContainer = document.createElement("div");

        // Now we need to create an input element
        this.#input = document.createElement("input"); // input is an inline element
        this.#input.type = "text";
        this.#divContainer.appendChild(this.#input); // putting our input element
        // into the div container.

        // now we need to add a button 
        this.#btnAdd = document.createElement("button");
        this.#btnAdd.textContent = "Add";
        this.#divContainer.appendChild(this.#btnAdd);

        // Now we will put the div container inside the parentContainer.
        this.#parentContainer.appendChild(this.#divContainer);


        // Now we will add an EventListener to the the button
        this.#btnAdd.addEventListener("click",
            (e) => this.addTo(list)
        )

        // adding another event listener on input , to add the item
        // when hit Enter
        this.#input.addEventListener("keypress",

            (e) => this.btnEnter(e, list)
        )


    }


    addTo(listElement) {
        let value = this.getText() // getting text from the input element.
        listElement.addItem(value) // method of list element.
        this.setText(""); // making empty to input element value.
    }

    btnEnter(e, list) {
        // this function is the event handler for key press events if our key is Enter.
        // console.log(e, e.key)
        if (e.key === "Enter") {
            this.addTo(list);
        }
    }

    getText() {
        // this method will get the text from the input.
        return this.#input.value;
    }

    setText(value) {
        this.#input.value = value;
        // setting the text to input .
    }


}

class List {

    #parentContainer = null;
    // A Container to hold the list, this must be private so that any changes to the list container
    // can not be made outside the class.

    // similarly we have a list Element.
    #element = null; // to hold the list itself.
    #elementType = null; // to store the type of the list container element.
    #listStyleType = null; // to store the list style type.
    #listElements = []; // an array to store the list elements.

    #input = null; // to take the input for next list item.

    constructor(parentContainer, type = 'ul') {
        // first we will set the parent Container and then we will set the
        // list element type.
        this.#parentContainer = parentContainer;
        this.#elementType = type;

        // Now we will make the list.
        this.#element = document.createElement(this.#elementType)


        // Now just before the list element we will put our InputAdd Object.
        this.#input = new InputAdd(this.#parentContainer, this)

        // Now we will put our list into it's parent container.
        this.#parentContainer.appendChild(this.#element);
    }

    addItem(content) {
        // In this, we will create an <li> element and then we will put some content in that list 
        // element.
        let li = document.createElement('li');
        li.innerText = content;

        // Now we will put this li element inside the our list element.
        this.#element.appendChild(li);
        this.#listElements.push(li);
    }

    getParent() {
        return this.#parentContainer;
    }

    setListStyleType(type) {

        if (type != undefined) {
            this.#listStyleType = type;
            this.#element.style.listStyleType = this.#listStyleType;
        }
        else {
            console.error("Error: You must specify the type of list style.")
        }
    }

    getListItems() {
        return this.#listElements
    }

}

/**==================================================== */

let myList = new List(listContainer);

myList.addItem("This is first element");

for (let i = 0; i < 5; i++) {
    myList.addItem(`This is ${i}th element`);
}

/**==================================================== */