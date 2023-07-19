const print = console.log;

print(localStorage)

let st = {
    name: "lokendra",
    age: 21,
    height: 5.6,
    bloodGroup: "AB+",
}

print(st)

// converting json object to string.
print(JSON.stringify(st))

// getting Database1 data from localStorage if present;

const data = localStorage.getItem("DataBase1")

if (data) {

    // converting string to json object
    print("DataBase1 Data: ", JSON.parse(data));
}


function isLocalExist(key) {
    return Object.keys(localStorage).includes(key)
}

function getLocalData(key, initial = false) {

    // first we will check that our key is exist or not
    if (isLocalExist(key)) {
        let data = localStorage.getItem(key)
        return JSON.parse(data);
    }
    else {
        if (initial) {
            // create a new database inside the localStorage
            localStorage.setItem(key, JSON.stringify([]));
            return getLocalData(key, initial = false)
        }
    }

    return null;

}

function saveToLocal(key, data) {

    if (data instanceof Array) {
        // first convert to string
        if (isLocalExist(key)) {
            let data_str = JSON.stringify(data);

            localStorage.setItem(key, data_str);
        }
        else {
            console.error(`KeyError: key '${key}' does not exist in local storage`);
        }
    }
    else {
        console.error("Error: data must be an array")
    }
}