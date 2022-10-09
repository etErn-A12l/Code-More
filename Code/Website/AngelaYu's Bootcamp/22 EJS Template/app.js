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
            res.render('index', { fuckingDay: day });
            break;
        case 1:
            day = "Monday";
            res.render('index', { fuckingDay: day });
            break;
        case 2:
            day = "Tuesday";
            res.render('index', { fuckingDay: day });
            break;
        case 3:
            day = "Wednesday";
            res.render('index', { fuckingDay: day });
            break;
        case 4:
            day = "Thursday";
            res.render('index', { fuckingDay: day });
            break;
        case 5:
            day = "Friday";
            res.render('index', { fuckingDay: day });
            break;
        case 6:
            day = "Saturday";
            res.render('index', { fuckingDay: day });
            break;
        default:
            break;
    }

});

app.listen(3000, () => console.log('Example app listening on port 3000!'));