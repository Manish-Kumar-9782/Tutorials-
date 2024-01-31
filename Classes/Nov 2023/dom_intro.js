
// to get the elements by using the tagName
// get all h1 heading.
let h1_s = document.getElementsByTagName("h1")

// this will get the only element having the id
// js-task.
let ul_list = document.getElementById("js-task")

// this will get all the list item present in the html
let all_list_items = document.getElementsByTagName("li")


// selecting only list item present inside the js-task ul 
// list.

let js_task_li_items = ul_list.getElementsByTagName("li")