// Create a list block or a container.

// li 

class InputElement {
    constructor(parent, list) {
        this.parent = parent;
        this.list = list;


        this.input = document.createElement('input');
        this.input.type = 'text';
        this.parent.appendChild(this.input);

        this.input.addEventListener('keydown', (e) => {
            if (e.key === 'Enter') {
                this.getText(this.list)
            }
        });
    }

    getText(list) {
        // list is an instance of ListElement
        list.addItem(this.input.value);
        this.input.value = ""; // resetting value of 
        // input element.
    }
}


class ListElement {

    constructor(parent, content) {
        /**
         * parent: it is an element which will contain the list item.
         * 
         * content: it is the content for our list item element.
         */
        this.parent = parent;
        this.content = content;

        // first creating the li element
        this.liElement = document.createElement("li");

        // now putting some text content inside that element.
        this.liElement.innerText = this.content;

        // now append this element inside the parent.
        this.parent.appendChild(this.liElement);
    }
}

// ul, ol
class ListContainer {

    // static LIST = []; // an array to hold all the list elements.

    constructor(parent, listType = 'ul') {
        this.listType = listType;
        this.parent = parent;
        this.items = [];
        // first we will create a new list element.
        this.listContainer = document.createElement(this.listType);

        // now append this element inside the parent.
        this.input = new InputElement(this.listContainer, this)
        this.parent.appendChild(this.listContainer);


    }

    addItem(content) {
        let li = new ListElement(this.listContainer, content);
        this.items.push(li);
    }

    deleteItem(index) {
        let element = this.items[index];
        element.liElement.remove();// remove method on element 
        this.items.splice(index, 1);
    }
}