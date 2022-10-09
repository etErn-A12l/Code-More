
import express from 'express'
import bodyParser from 'body-parser'
// const bodyParser = require('body-parser')   // module to get parsed requests

import { fileURLToPath } from 'url';
import { dirname } from 'path';

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);

const app = express()
app.use(bodyParser.urlencoded({ extended: true })) // using body parser to get urlencoded form data

app.get('/', (req, res) => {
    res.sendFile(__dirname + "/index.html")
});

app.post("/", (req, res) => {

    var num1 = Number(req.body.num1)
    var num2 = Number(req.body.num2)

    var sum = num1 + num2

    res.send("The sum is: " + sum)
})

app.listen(6400, () => {
    console.log("Listening on Port 6400");
})