
const listContainer = document.getElementById('listContainer');

class CreateElement {
    #element = null;

    constructor(element, parent, options) {
        this.#element = document.createElement(element);

        // Now we will append this element into the document.
        parent.appendChild(this.#element);

        if (options.textContent) {
            this.#element.textContent = options.textContent
        }

        if (options.class) {
            this.#element.setAttribute("class", options.class);
        }

        if (options.id) {
            this.#element.setAttribute("id", options.id);
        }
    }

    get() {
        return this.#element
    }
}

class Input extends CreateElement {


    constructor(parent, options) {

        super("input", parent, options)
        this.parent = parent;
        this.input = super.get();

        if (options.type) {
            this.input.type = options.type;
        }
    }

}

class InputAdd {

    #parent = null;
    #input = null;
    #btn = null;
    #list = null;

    constructor(parent, inputOptions, btnOptions) {

        let container = new CreateElement("div", listContainer, {
            class: "container"
        }).get();
        this.#input = new Input(container, inputOptions).get();
        this.#btn = new CreateElement('button', container, btnOptions).get();

        this.#parent = parent;
    }
}

class List extends CreateElement {

    #list = null;
    #listType = null;
    #input = null;
    #parent = null;

    constructor(parent, options, list = "ul") {
        super(parent, list, options)
        this.#parent = parent;
        this.#listType = list;
        this.#list = super.get();


    }
}