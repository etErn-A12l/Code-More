// Creating First Template

import express from 'express';

const app = express();

app.set('view engine', 'ejs');

var date = new Date();
var today = date.getDay();  // if Sunday, then returns 0
var day = "";
app.get('/', (req, res) => {

    switch (today) {
        case 0:
            day = "Sunday";
            break;
        case 1:
            day = "Monday";
            break;
        case 2:
            day = "Tuesday";
            break;
        case 3:
            day = "Wednesday";
            break;
        case 4:
            day = "Thursday";
            break;
        case 5:
            day = "Friday";
            break;
        case 6:
            day = "Saturday";
            break;
        default:
            break;
    }

    res.render('index', { fuckingDay: day });   // Passes the value od day variable to fuckingDay variable of index.ejs from view folder

});

app.listen(3000, () => console.log('Example app listening on port 3000!'));