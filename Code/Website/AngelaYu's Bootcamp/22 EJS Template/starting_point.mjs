import express, { application } from 'express'

import bodyParser from 'body-parser'

const app = express();

var date = new Date();
var today = date.getDay();  // if Sunday, then returns 0

app.get("/", (req, res) => {

    if (today === 6 || today === 0) {
        res.write("Ah yeah babe !");
    }
    else {
        res.write("<p>Ah fucking Work..</p>")
        res.write("<h1>Fuuucckkkkkkkk</h1>")
        res.send();
    }

});

app.listen(3000, () => {
    console.log("Server started listening on port 3000..");
})