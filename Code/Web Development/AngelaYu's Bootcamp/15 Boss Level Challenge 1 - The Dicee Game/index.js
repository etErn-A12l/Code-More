
let index1 = Math.floor(Math.random() * 6) + 1;
let index2 = Math.floor(Math.random() * 6) + 1;

var src1 = "images/dice" + index1 + ".png";
var src2 = "images/dice" + index2 + ".png";

document.querySelectorAll("img")[0].setAttribute("src", src1);
document.querySelectorAll("img")[1].setAttribute("src", src2);

if (index1 > index2) {
    document.querySelector("h1").innerHTML = "Player1 Wins";
}
else if (index2 > index1) {
    document.querySelector("h1").innerHTML = "Player2 Wins";
}
else {
    document.querySelector("h1").innerHTML = "Draw";
}
