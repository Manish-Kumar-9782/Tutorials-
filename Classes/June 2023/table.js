
function createTable(container, header) {

    this.table = document.createElement("table");
    this.thead = document.createElement("thead");
    this.tbody = document.createElement("tbody");

    this.table.appendChild(this.thead);
    this.table.appendChild(this.tbody);

    // to add heading row.
    if (header) {
        this.addRow(header, false, "th");
    }

    container.appendChild(this.table);
}

createTable.prototype.addRow = function (data, body = true, type = 'td') {
    const row = document.createElement("tr");

    data.forEach((item) => {
        const td = document.createElement(type);
        td.innerText = item;
        row.appendChild(td);
    })

    if (body) {
        this.tbody.appendChild(row);
    }
    else {
        this.thead.appendChild(row);
    }

}


