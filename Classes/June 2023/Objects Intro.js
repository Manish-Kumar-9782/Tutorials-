
let myObject = {
    name: 'dinesh',
    age: 21,
    height: 6.2,
    weight: 66
}

let myObject2 = {
    "name": 'dinesh',
    "age": 21,
    "height": 6.2,
    "weight": 66
}


console.log(myObject);
console.log(myObject2);

// Assessing object item by using . member operator

console.log("myObjects's Name: ", myObject.name);
console.log("myObjects's Age: ", myObject.age);
console.log("myObjects's Height: ", myObject['height']);

// assigning new values to specific properties
myObject.age = 22;
console.log(myObject);

// adding new properties
myObject.bloodGroup = "AB+";

console.log(myObject);

// deleting property from object
delete myObject.bloodGroup;
console.log(myObject);


// keys, values, entries;
console.log("myObject Keys: ", Object.keys(myObject));
console.log("myObject Values: ", Object.values(myObject));
console.log("myObject Entries: ", Object.entries(myObject));


// Student Object Constructor

function Student(name, rollno, std, school) {
    this.name = name;
    this.rollno = rollno;
    this.std = std;
    this.school = school;

}

let st1 = new Student("Dinesh", 1234, "12th", "TechInnovation");
let st2 = new Student("Kushal", 5435, "10th", "TechInnovation2");

function showStudent(st) {

    let info = `Student<${st.name}>{\n`;
    info += `\tName: ${st.name}\n`;
    info += `\tRollNo: ${st.rollno}\n`;
    info += `\tClass: ${st.std}\n`;
    info += `\tSchool: ${st.school}\n`;
    info += `}`;

    console.log(info);
}

Student.prototype.showStudent = function () {
    let info = `Student<${this.name}>{\n`;
    info += `\tName: ${this.name}\n`;
    info += `\tRollNo: ${this.rollno}\n`;
    info += `\tClass: ${this.std}\n`;
    info += `\tSchool: ${this.school}\n`;
    info += `}`;

    console.log(info);
}