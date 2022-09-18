
function add(num1, num2) {
    return num1 + num2;
}

function multiply(num1, num2) {
    return num1 * num2;
}

function calculator(num1, num2, operator) {
    return operator(num1, num2);
}


add(1,2);
calculator(1,2,add); // Both are same