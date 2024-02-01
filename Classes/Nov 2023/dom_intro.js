
// to get the elements by using the tagName
// get all h1 heading.
let h1_s = document.getElementsByTagName("h1")

// this will get the only element having the id
// js-task.
let ul_list = document.getElementById("js-task")
let ol_list = document.getElementById("ol-list")

// this will get all the list item present in the html
let all_list_items = document.getElementsByTagName("li")


// selecting only list item present inside the js-task ul 
// list.

let js_task_li_items = ul_list.getElementsByTagName("li")



// highlighting the JavaScript word from list.

// const word = prompt("Enter word: ")
// const replaceBy = prompt("new word: ")

// for (let i = 0; i < js_task_li_items.length; i++) {
//     let li_item = js_task_li_items[i]
//     let li_item_content = li_item.innerHTML

//     li_item.innerHTML = li_item_content.replaceAll(
//         word, replaceBy)
// }


function removeItem(parentNode) {

    let childNodeIndex = prompt("child node index: ")

    parentNode.removeChild(parentNode.children[childNodeIndex])

}