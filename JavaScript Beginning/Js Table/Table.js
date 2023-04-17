
// 1. create a new Class for Table 

class Table {

    // constructor for Table
    // headers: ["Name","Age","Height","BloodGroup"]
    constructor(parent, row, column, headers) {
        this.parent = parent;
        this.table = document.createElement('table') // creating a table element.
        this.rows = Number(row);
        this.columns = Number(column);
        // Now we need to put that into the container.
        this.parent.appendChild(this.table); // putting table element into the container.

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

    addRowColumns(data, cellElement = 'td',) {
        let row = this.addRow();
        // Now in each row we need to add columns
        for (let i = 0; i < this.columns; i++) {
            this.addColumn(row, cellElement, data[i]);
        }
    }

    setHeader(headers) {
        this.addRowColumns(headers, "th")
    }

}