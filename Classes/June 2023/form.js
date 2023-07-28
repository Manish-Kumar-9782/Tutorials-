
const myForm = document.forms['myform'];
// getting the form element object modal.

// Now we need to access each input data by using id.

function genId() {
    return Math.round(Math.random() * 1000000000);
}

function getFormData(form) {

    const firstName = form['firstname'].value;
    const secondName = form['secondname'].value;
    const Age = form['age'].value;
    const Height = form['height'].value;
    const Gender = form['gender'].value;
    const isMarried = form['married'].checked;
    const Subject = form['subject'].value;
    const Description = form['description'].value;

    return { firstName, secondName, Age, Height, Gender, isMarried, Subject, Description };
}

function displayFormData(form) {

    const { firstName, secondName, Age, Height, Gender, isMarried, Subject, Description } = getFormData(form);

    const display = console.log;

    display(`First Name: ${firstName}`);
    display(`Second Name: ${secondName}`);
    display(`Age: ${Age}`);
    display(`Height: ${Height}`);
    display(`Gender: ${Gender}`);
    display(`isMarried: ${isMarried}`);
    display(`Subject: ${Subject}`);
    display(`Description: ${Description}`);
}


function save_toLocalStorage(form) {
    const data = getFormData(form);

    // first get data
    if (localStorage.getItem("DataBase1")) {
        const data = JSON.parse(localStorage.getItem("DataBase1"));

        const key = genId();
        const itemData = getFormData(form);

        data.push({ [key]: itemData })

        // now save the data
        localStorage.setItem("DataBase1", JSON.stringify(data));
        return
    }
    else {
        localStorage.setItem("DataBase1", JSON.stringify([]));
        save_toLocalStorage(form);
    }


}

myForm.addEventListener("submit", (e) => {

    e.preventDefault();
    displayFormData(myForm);

    let localData = getLocalData("LocalData", true);
    localData.push(getFormData(myForm));

    saveToLocal("LocalData", localData);

    myForm.reset();
})



// getting data from local storage
const localData = getLocalData("LocalData")

const header = Object.keys(localData[0])

const localDataTable = new createTable(document.body, header)

localData.forEach((item) => {
    localDataTable.addRow(Object.values(item))
})