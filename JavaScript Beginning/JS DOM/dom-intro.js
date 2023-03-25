// document.getElementById() --> it will take id name
// document.getElementsByClassName() --> it will take class name
// document.getElementsByTagName() --> it will take tagName
// document.querySelector(); --> it will take css selector
// document.querySelectorAll();

const myHeading = document.getElementById("myheading");

// displaying the myHeading element on console.
console.log(myHeading);
/**
 * innerText
 * innerHTML
 * appendChild
 * remove
 * style --> it is used to set css styles.
 */

const myDiv = document.getElementById("mydiv");

let list = ["cooking cookies", "making bed", "washing cloths", "Runnig at 6"]

let content = ""
content += "<ul>"
list.forEach((item) => {
    content += `<li>${item}</li>`
})
content += "</ul>"

/**
 * document.createElement()
 * Element.appendChild()
 */

// first create ul element.
let ul = document.createElement("ul")

// let liElements = []

list.forEach(item => {
    let li = document.createElement("li");
    li.innerText = item;
    // liElements.push(li);
    ul.appendChild(li);
})