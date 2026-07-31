// express server

const express = require('express');
const app = express();
require('dotenv').config();

app.get('/', (req, res)=>{
  res.send("Welcome to the study stack api");
})

// app.get('/courses', (req, res)=>{
//   res.json({message: 'Listing all the courses'});
// })
// app.post('/courses', (req, res)=>{
//   res.json({message: 'creating the courses'});
// })
// app.put('/courses', (req, res)=>{
//   res.json({message: 'updating all the courses'});
// })
// app.delete('/courses/:id', (req, res)=>{
//   res.json({message: 'deleting the courses'});
// })





// ------------------------------------------------------------------------
// node server

// const path = require('path');
// const http = require('http');

// const server = http.createServer((req, res)=>{
//   // req
//   console.log(`Method: ${req.method}`);
//   console.log(`Method: ${req.url}`);
  
//   // res
//   res.end(JSON.stringify("Hello From Node.js"))
// })

// let PORT = 4000;
// server.listen(PORT, ()=>{
//   console.log("Server is live on 4000")
// })



