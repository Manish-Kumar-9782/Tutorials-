
let Bhanu = {
    name: "bhanu",
    age: 18,
    height: 5.5,
    bloodGroup: "AB+"
}

console.log(Bhanu)

let Lokendra = {
    name: "lokendra",
    age: 20,
    height: 6.1,
    bloodGroup: "B+"
}
console.log(Lokendra)


function showInfo(name, age, height, bloodGroup) {
    // statements
    console.log('-------------------------------\nName: ', name);
    console.log('Age: ', age);
    console.log('Height: ', height);
    console.log('BloodGroup: ', bloodGroup, "\n----------------------------------");
    console.log("\n")
}

// console.log(age);

showInfo("kuch bhi", "nhi pata", "lambu", "anjan");

showInfo("kuldeep", 21, 5.6, "B+");

showInfo("Keshav", 20, 5.8, "B+");

showInfo(Bhanu.kuldeep, Bhanu.age, Bhanu.height, Bhanu.bloodGroup)