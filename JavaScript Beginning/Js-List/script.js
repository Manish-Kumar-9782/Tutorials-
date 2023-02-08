
// first of all we will get the list Container.

const listContainer = document.getElementById('listContainer');

// Now after getting this list container will make a class to create the list blocks.

class List {

    #parentContainer = null;
    // A Container to hold the list, this must be private so that any changes to the list container
    // can not be made outside the class.

    // similarly we have a list Element.
    #element = null; // to hold the list itself.
    #elementType = null; // to store the type of the list container element.
    #listStyleType = null; // to store the list style type.
    #listElements = []; // an array to store the list elements.

    constructor(parentContainer, type = 'ul') {
        // first we will set the parent Container and then we will set the
        // list element type.
        this.#parentContainer = parentContainer;
        this.#elementType = type;

        // Now we will make the list.
        this.#element = document.createElement(this.#elementType)


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