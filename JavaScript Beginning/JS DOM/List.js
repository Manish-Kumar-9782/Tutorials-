// Create a list block or a container.

/*
    1. create an element (any type)
    2. attach (put) that element to the the document.
    3. add attribute and content to the created element.
*/

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

    constructor(parent, content, listContainer) {
        this.parent = parent;
        this.content = content;
        this.listContainer = listContainer;
        // first creating the li element
        this.liElement = document.createElement("li"); // list item
        this.spanContent = document.createElement("span"); // span for text
        this.actions = document.createElement("div"); // actions a dive to contain 

        // putting spanContent and actions into the li Element
        this.liElement.appendChild(this.spanContent);
        this.liElement.appendChild(this.actions)

        // creating the edit and delete button 
        this.editButton = document.createElement("button"); // edit button
        this.deleteButton = document.createElement("button"); // delete button


        // inserting the delete and edit button inside the actions.
        this.actions.appendChild(this.editButton);
        this.actions.appendChild(this.deleteButton);

        // now putting some text content inside that element.actions
        this.spanContent.innerText = this.content;
        this.deleteButton.innerText = "Delete";
        this.editButton.innerText = "edit";

        // Optional
        this.liElement.classList.add("d-flex");
        this.liElement.classList.add("justify-content-between");

        // now append this element inside the parent.
        this.parent.appendChild(this.liElement);


        // an event listener to delete the element.
        this.deleteButton.addEventListener("click", (e) => this.delete(e))

        // adding a new event listener for edit button
        this.editButton.addEventListener("click", (e) => this.edit(e));
    }

    setId(index) {
        this.deleteButton.dataset.id = index;
    }

    delete(e) {
        let index = this.listContainer.items.indexOf(this)
        this.listContainer.deleteItem(index);

    }

    edit(e) {
        let text = this.spanContent.innerText;
        this.listContainer.input.value = text;
        this.listContainer.updateRef = this.spanContent;
    }

}

// ul, ol
// static LIST = []; // an array to hold all the list elements.
class ListContainer extends LocalDatabase {
    constructor(parent, listType = 'ul') {
        super({})
        this.listType = listType;
        this.parent = parent;
        this.items = [];
        this.updateRef = null; // to hold the reference of the element for which we need to update the content

        // first we will create a new list element.
        this.listContainer = document.createElement(this.listType);

        // now append this element inside the parent.
        this.input = document.createElement("input");
        // appending the element to the list container.
        this.listContainer.appendChild(this.input);

        this.input.addEventListener('keydown', (e) => {
            if (e.key === 'Enter') {

                if (this.updateRef) {
                    // if we have any element ref inside the this.updateRef variable.
                    this.updateRef.innerText = this.input.value;
                    this.input.value = '';
                    this.updateRef = null;
                } else {
                    this.getText()
                }
            }
        });

        this.parent.appendChild(this.listContainer);
    }

    addItem(content) {
        let li = new ListElement(this.listContainer, content, this);
        this.items.push(li);
        li.setId(this.items.indexOf(li));
    }

    deleteItem(index) {
        let element = this.items[index];
        element.liElement.remove();// remove method on element 
        this.items.splice(index, 1);
    }

    setClass(str) {
        this.listContainer.classList.add(str);
    }

    setClasses(class_array) {
        class_array.forEach((cls) => this.setClass(cls));
    }
    getText() {
        // list is an instance of ListElement
        this.addItem(this.input.value);
        this.input.value = ""; // resetting value of 
        // input element.
    }

    getItems() {
        return this.items.map((item) => item.spanContent.innerText);
    }

    save() {

        this.constructor.setRecord(`List-${this.constructor.Records.indexOf(this)}`, this.getItems())
    }
}