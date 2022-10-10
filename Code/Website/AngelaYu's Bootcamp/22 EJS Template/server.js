import Express from "express";
import bodyParser from 'body-parser';

const app = Express();

app.use(bodyParser.urlencoded({
    extended: true
})); // using body parser to get urlencoded form data

app.use(Express.static("public")); // Telling Express to use the 'public' folder as a source of static files, ex: css files

app.set('view engine', 'ejs');

var options = {
    weekday: 'long',
    year: 'numeric',
    month: 'long',
    day: 'numeric'
};

var today = new Date();
var Fulldate = today.toLocaleDateString("en-US", options);
var tasks = ["Push Ups", "Brush", "Tiffin", "Career"]; // The array for tasks in root route
var workTasks = []; // The array for tasks in work route


// console.log(Fulldate);

app.get("/", (req, res) => {
    res.render('todolist', {
        TodayDate: Fulldate,
        NewItem: tasks
    }); // Rendering the website with data of variables
});

app.post('/', (req, res) => {

    var task = req.body.Task; // Getting the task given by user

    console.log(req.body.submit); // seeing the value of button in diferent route

    if (req.body.submit === "Work") { // Checking where the post req came from through button value
        workTasks.push(task); // Appending to workTasks array
        res.redirect("/work"); // redirecting to app.get() method to re-render the site with new values to /work route
    } else {
        tasks.push(task); // Appending to tasks array
        res.redirect("/"); // redirecting to app.get() method to re-render the site with new values to / route
    }

});

app.get("/work", (req, res) => {
    res.render("todolist", {
        TodayDate: "Work List",
        NewItem: workTasks
    });
});

app.get("/about", (req, res) => {
    res.render("about");
})

app.listen(3000, () => {
    console.log('App Started Listening on port 3000..');
});