
// 1. first of all we need to get th form.

const form = document.getElementById('myForm');

const inputs = [...form.getElementsByTagName('input')];


inputs.forEach(input => {

    input.addEventListener('change', function () {
        input.classList.add('validate');
    })

});

function validatePassword(password) {

    let isCapital = false;
    let isDigit = false;
    let isSpecial = false;

    for (let i = 0; i < password.length; i++) {

        // first we will test of capital character.
        const char = password[i].charCodeAt();
        if (char > 65 && char <= 90) {
            // Captical Charactre found.
            isCapital = true;
        }
        else if (char > 48 && char <= 57) {
            // finding the number 
            isDigit = true;

        }
        else if ((char >= 33 && char <= 47) || (char > 58 && char <= 64)) {
            // finding the special character.
            isSpecial = true;
        }
    }
    console.log("Password: ", password);
    console.log("isCapital:", isCapital);
    console.log("isDigit:", isDigit);
    console.log("isSpecial:", isSpecial);

    return isCapital && isDigit && isSpecial;
}



form.addEventListener('submit', (e) => {
    e.preventDefault();
    // preventing from submitting and reload the page.

    const password = form['password'].value;
    const isValid = validatePassword(password);

    if (!isValid) {
        form['password'].classList.remove('validate');
        form['password'].classList.add('invalid');

    }
});