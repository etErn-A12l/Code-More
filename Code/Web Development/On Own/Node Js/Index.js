console.log("Hello world")

// Variables

var aluvate = 12; // number
var muri = "shyam"; // string
var we = true; // boolean
var tyt = 23.34; // float

var marks =     // object
{
    ravi: 12,
    asjd: 543,
    zfg: 89
}

console.log("The sum of the numbers are " + (aluvate + muri))

var arr = [12, 56, 78, 23, 56, 90]

// For loop 1st Method 
console.log("\n1st Method for loop")

for (var i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}

// For Loops 2nd Method
console.log("2nd Method for loop")

arr.forEach(function (element) {
    console.log(element);
})

// While Loop
console.log("Now running while loop")
let k = 0;
while (k < arr.length) {
    console.log(k);
    k++;
}

// Do While Loop
console.log("Now running Do While loop")
do {
    console.log(k);
    k--;
}
while (k >= 0);

function ami_jani_na(a, b) {
    console.log("This function is dividing two numbers " + a / b)
}

ami_jani_na(12, 4) // Calling the function

let date = new Date();

console.log(date)

console.log(date.getHours)


var name = prompt("What is your name ? ");

var statement = "I am incredible";

var length_of_statement = statement.length;

// Twitter slicer

var tweet = prompt("Enter your tweet: ");
var length_of_statement = tweet.length;
alert('You have written ' + length_of_statement + ' characters and you left ' + 140 - length_of_statement);
alert("Cutting your tweet in 140 words....");
tweet = tweet.slice(0, 141);
alert(tweet);

 