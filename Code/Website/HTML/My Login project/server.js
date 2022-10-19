import express from "express"
import ejs from "ejs"
import bodyParser from "body-parser"

const app = express();
// const {
//     check,
//     validationResult
// } = require('express-validator');

import {
    check,
    validationResult
} from "express-validator";

app.use(express.static("public"));

app.use(bodyParser.urlencoded({
    extended: true
}));

app.set('view engine', 'ejs');


app.get("/", (req, res) => {
    res.render("login");
})

app.post("/", [
    check('mailId', 'Email length should be 10 to 30 characters')
    .isEmail().isLength({
        min: 10,
        max: 30
    }),
    check('passwd', 'Password length should be 8 to 10 characters')
    .isLength({
        min: 8
    })
], (req, res) => {
    let userEmail = req.body.mailId;
    let userPassword = req.body.passwd;
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
        // return res.status(422).json({
        //     errors: errors.array()
        // });
        console.log(errors)
        throw new Error('Password confirmation is incorrect');
    } else {
        res.send("Nice Babe !")
    }
})





app.listen(3000, () => {
    console.log("App started listening on port 3000...");
})