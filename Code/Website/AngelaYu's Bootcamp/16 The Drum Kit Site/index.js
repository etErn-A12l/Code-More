
let numberOfDrums = document.querySelectorAll(".drum").length;

// For Detecting Mouse Click
for (let i = 0; i < numberOfDrums; i++) {

    document.querySelectorAll(".drum")[i].addEventListener("click", function () {

        // alert("You are Awesome");

        var innerHTML = this.innerHTML;
        playAudio(innerHTML);
        btnAnimation(innerHTML);
    });
}

// For Detecting Keyboard Press
document.addEventListener("keypress", function (event) {

    playAudio(event.key);
    btnAnimation(event.key);
})

function playAudio(key) {

    switch (key) {
        case 'w':
            var audio = new Audio('sounds/crash.mp3');
            audio.play();
            break;
        case 'a':
            audio = new Audio('sounds/kick-bass.mp3');
            audio.play();
            break;
        case 's':
            audio = new Audio('sounds/snare.mp3');
            audio.play();
            break;
        case 'd':
            var audio = new Audio('sounds/tom-1.mp3');
            audio.play();
            break;
        case 'j':
            var audio = new Audio('sounds/tom-2.mp3');
            audio.play();
            break;
        case 'k':
            var audio = new Audio('sounds/tom-3.mp3');
            audio.play();
            break;
        case 'l':
            var audio = new Audio('sounds/tom-4.mp3');
            audio.play();
            break;
        default:
            break;
    }
};

function btnAnimation(key) {

    var Activebtn = document.querySelector("." + key);

    Activebtn.classList.add("pressed"); // pressed class is created in style.css

    setTimeout(function () {
        Activebtn.classList.remove("pressed");
    }, 150);
};