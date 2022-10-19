import express from 'express'
const app = express()
const port = 3000

app.get('/', (req, res) => {    // Sends a response to root directory
    res.send('<h1>Hello World!</h1>')
})

app.get('/about', (req, res) => {
    res.send("Nothing about me")    // 127.0.0.1:3000/about
})

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)  // starts listening on port 3000
})

// node server.js

// localhost:3000