
const fs = require('fs');
const path = require('path');
const express = require('express');
const app = express();
const axios = require('axios');
const mongoose = require('mongoose');
require('dotenv').config();


const connectDB = async () => {
  try {
    await mongoose.connect(process.env.DATABASE);
    console.log("connection estabslished");
  } catch (err) {
    console.error("connection error", err);
    process.exit(1);
  }
}

connectDB();



// courses schema
const courseSchema = new mongoose.Schema({
  title: {
    type: String,
    required: true,
    // unique: true
  },
  price: {
    type: Number,
    required: true,
    min: [0, "Price should be gretaer than 0"]
  },
  instructor: {
    type: String,
    required: true
  }
})

const Course = mongoose.model("Course", courseSchema, "Courses");

// seed data to database
// const filepath = path.join(__dirname, "./data/data.json")
// const data = JSON.parse(fs.readFileSync(filepath, 'utf-8'));
// const seedData = async()=>{
//   try{
//     await Course.create(data);
//     console.log("Data imported");
//   }catch(err){
//     console.error("Data not imported", err);
//   }
// }
// seedData();



// CREATE
app.post('/api/courses', async (req, res) => {
  try {
    const course = await Course.create(req.body);
    res.status(200).json(course);
  } catch (err) {
    res.status(400).json({ error: err.message });
  }
})

// GET
app.get('/api/courses', async (req, res) => {
  try {
    const filter = req.query.instructor ? { instructor: req.query.instructor } : {};
    const courses = await Course.find();
    // const courses = await Course.find(filter);
    res.json(courses);
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
})

// GET ONE
app.get('/api/courses/:id', async (req, res) => {
  try {
    const course = await Course.findById(req.params.id);
    if(!course) return res.status(404).json({error: "Course not found"});
    // const courses = await Course.find(filter);
    res.json(courses);
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
})
// DELETE
app.get('/api/courses/:id', async (req, res) => {
  try {
    const course = await Course.findByIdAndDelete(req.params.id);
    if(!course) return res.status(404).json({error: "Course not found"});
    // const courses = await Course.find(filter);
    res.json(courses);
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
})
// UPDATE
app.get('/api/courses/:id', async (req, res) => {
  try {
    const course = await Course.findByIdAndUpdate(req.params.id);
    if(!course) return res.status(404).json({error: "Course not found"});
    // const courses = await Course.find(filter);
    res.json(courses);
  } catch (err) {
    res.status(400).json({ message: err.message });
  }
})




app.get('/', (req, res) => {
  res.send("Welcome to the study stack api");
})


// async function getUsers(){
//   const data = await axios.get("https://dummyjson.com/users");
//   // console.log(data.users);
//   data.users.forEach(user=>{
//     console.log(user.firstName)
//   })
// }

// getUsers();


// courses db
// const courses = [
//   {"id":1001, "name": "Node.js", "price": 5999},
//   {"id":1002, "name": "C++", "price": 3999},
//   {"id":1003, "name": "Java", "price": 4999},
//   {"id":1004, "name": "Python", "price": 7999},
// ]

// function validateCourse(req, res, next){
//   const {id, title, price} = req.body;
//   if(!id || !title || !price){
//     return res.json({error: "Invalid course details"});
//   }
//   if(price <= 0){
//     return res.json({error: "Invalid course details, price must be > 0"});
//   }
//   next();
// }

// app.get('/api/courses', (req, res)=>{
//   res.json(courses);
// })

// app.get('/api/courses/:id', (req, res)=>{
//   const course = courses.find(c=>c.id == req.params.id);
//   if(!course) return res.status(404).json({error: "Course not found"})
//   res.json(course);
// })

// // TASK - post method implement
// app.post('/api/courses', validateCourse, (req, res)=>{
//   const newCourse = {
//     "id": 1005,
//     "title": "DevOps",
//     "price": 8999
//   }
//   courses.push(newCourse);
//   res.status(201).json({message: "new course created"});
// })

// // Delete
// app.delete('/api/courses/:id', (req, res)=>{
//   const course = courses.find(c=>c.id == req.params.id);
//   if(!course) return res.status(404).json({error: "Course not found"})
//   courses = courses.filter(c=>c.id != req.params.id);
//   res.status(200).json({message: "course deleted"});
// })




let PORT = process.env.PORT || 5000;
app.listen(PORT, () => {
  console.log(`express server is live on ${PORT}`)
})