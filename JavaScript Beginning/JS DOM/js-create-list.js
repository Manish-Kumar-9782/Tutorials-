// first get the list container

let container = document.getElementById('list-container')

let addListButton = document.getElementById('add-list');

const Lists = []

addListButton.addEventListener('click', function (e) {
    let list = new ListContainer(container)
    list.setClasses(["border", "m-4", "p-4", "border-dark", "w-25"])
    Lists.push(list);
})