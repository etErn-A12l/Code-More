
function Student(name, section, roll) {
    this.name = name;
    this.section = section;
    this.roll = roll;
    this.exam = function () {
        alert("I am " + name + " NO Fucking exam !!");
    }
}

var Student1 = new Student("Sreejan", "A", 12);

Student1.exam(); // Fucking exam !!