// first we need to get the form
const libraryForm = document.forms["library"];
const database = document.getElementById("showdatabase");
const showDatabaseThead = document.getElementById("showdatabase-thead");
const showDatabaseTbody = document.getElementById("showdatabase-tbody");

// now we need to bind the buttons 

const addbookButton = document.getElementById("addBook");
const showbookButton = document.getElementById("showBook");
const editRowButton = Array(...document.getElementsByClassName("edit-row"));

showbookButton.onclick = () => {
    // first we need to hind the addbook form
    libraryForm.style.display = "none";
    // Now we need to show the database table.
    database.style.display = "block";

}

addbookButton.onclick = () => {
    // first we need to show the addbook form
    libraryForm.style.display = "block";
    // Now we need to hide the database table.
    database.style.display = "none";
}


// editRowButton.forEach(button => {
//     button.onclick = (event) => {
//         let rowData = event.target.parentElement.parentElement.children;
//         libraryForm["title"].value = rowData[0].innerText;
//         libraryForm["author"].value = rowData[1].innerText;
//         libraryForm["subject"].value = rowData[2].innerText;
//         libraryForm["pages"].value = rowData[3].innerText;
//         libraryForm['price'].value = rowData[4].innerText;
//         console.log(rowData);

//         libraryForm.style.display = "block";
//         // Now we need to hide the database table.
//         database.style.display = "none";
//     }
// })
