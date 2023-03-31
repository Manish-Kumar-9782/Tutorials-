let form = document.forms['TextInput'];

let myInput = form["textInput"];

let ulList = new ListContainer(
    document.getElementById("list-container")
)

form.addEventListener("submit", function (e) {
    e.preventDefault();
    ulList.addItem(myInput.value)
    form.reset();
})


