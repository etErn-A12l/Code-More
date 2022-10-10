import Express from "express";
import bodyParser from 'body-parser';

const app = Express();

app.use(bodyParser.urlencoded({
    extended: true
})); // using body parser to get urlencoded form data

app.use(Express.static("public"));  // Telling Express to use the 'public' folder as a source of static files, ex: css files

app.set('view engine', 'ejs');

var options = {
    weekday: 'long',
    year: 'numeric',
    month: 'long',
    day: 'numeric'
};

var today = new Date();
var Fulldate = today.toLocaleDateString("en-US", options);
var tasks = ["Push Ups", "Brush", "Tiffin", "Career"]; // The array for tasks

// console.log(Fulldate);

app.get("/", (req, res) => {
    res.render('todolist', {
        TodayDate: Fulldate,
        NewItem: tasks
    }); // Rendering the website with data of variables
});

app.post('/', (req, res) => {
    var task = req.body.Task; // Getting the task given by user
    tasks.push(task); // Appending to tasks array
    res.redirect("/"); // redirecting to app.get() method to re-render the site with new values
});

app.listen(3000, () => {
    console.log('App Started Listening on port 3000..');
});