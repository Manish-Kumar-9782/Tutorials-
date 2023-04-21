
// 1. create a new Class for Table 

class Table {


    // constructor for Table
    // headers: ["Name","Age","Height","BloodGroup"]
    constructor(parent, row, column, headers, form) {

        this.TableRecord = []
        this.currentId = 0
        this.Headers = null;
        this.form = form
        this.parent = parent;
        this.table = document.createElement('table') // creating a table element.
        this.rows = Number(row);
        this.columns = Number(column);
        // Now we need to put that into the container.
        this.parent.appendChild(this.table); // putting table element into the container.
        this.Headers = headers;
        // adding rows and columns to the table
        this.setHeader(headers);
    }

    addRow() {
        // now we will create a new <tr> element and holding inside the row variable.
        let row = document.createElement('tr');
        // putting this row into the table.
        this.table.appendChild(row);
        return row;
    }

    addColumn(row, cellElement, text) {
        // Now we will create a new <th> element and holding inside the column variable.
        let column = document.createElement(cellElement);
        // and putting this column into the row.
        column.innerText = text;
        row.appendChild(column);
    }

    addRowColumns(data, cellElement = 'td', actions = true) {
        let row = this.addRow();
        // Now in each row we need to add columns
        let dataObj = {}
        for (let i = 0; i < this.columns; i++) {
            this.addColumn(row, cellElement, data[i]);
            dataObj[this.Headers[i]] = data[i];
        }

        // after adding all columns we will add delete button.

        if (actions) {
            dataObj.id = this.currentId++;
            this.TableRecord.push(dataObj);
            this.#addDeleteButton(row, dataObj.id);
            this.#addEditButton(row, dataObj.id);
        }
    }

    setHeader(headers) {
        this.addRowColumns(headers, "th", false)
    }

    #addDeleteButton(row, id) {
        // create a new button element
        let button = document.createElement("button");
        button.innerText = "Delete";
        row.appendChild(button);
        button.addEventListener("click", (e) => {
            row.remove();
            this.TableRecord = this.TableRecord.filter(item => item.id !== id)
        })
    }

    #addEditButton(row, id) {
        let button = document.createElement("button");
        button.innerText = "Edit";
        row.appendChild(button);
        button.addEventListener("click", (e) => {
            let data = null;
            for (let item of this.TableRecord) {
                if (item.id === id) {
                    this.form['name'].value = item.Name
                    this.form['age'].value = item.Age
                    this.form['height'].value = item.Height
                    this.form['bloodGroup'].value = item.BloodGroup
                }
            }
        })
    }

}