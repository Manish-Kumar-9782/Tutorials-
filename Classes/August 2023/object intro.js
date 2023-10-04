
/**
 * object:
 * 
 *  let Object_name = {
 *      key: value,
 *      "key": value
 * }
 * 
 */

let Student = {
    name: 'pooja',
    age: 21,
    "height": 5.5,
    bloodGroup: "AB+",
}

let Student2 = {
    name: 'kunal',
    age: 22,
    "height": 5.7,
    bloodGroup: "B+",
}

function createStudent() {

    const student = {} // blank object

    let name = prompt("Enter Student name ")
    student.name = name; // adding a property to student called name.

    let age = prompt("Enter Student age ")
    student.age = age; // adding a property to student called age

    let height = prompt("Enter Student height ")
    student.height = height; // adding a property to student called height

    return student;
}

const Students = []; // empty array

for (let i = 0; i < 3; i++) {

    let st = createStudent();
    Students.push(st);
}




