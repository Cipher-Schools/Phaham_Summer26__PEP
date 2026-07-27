typeof "hello";    // "string"
typeof 42;         // "number"
typeof true;       // "boolean"
typeof undefined;  // "undefined"
typeof function(){}; // "function"
typeof {};         // "object"
typeof [];         // "object"  <-- arrays are objects
typeof null;       // "object"  <-- historical JavaScript quirk

// variables 

let num = 1; // block level
const str = "Phaham" // block level  

num = 10

var num2 = 3; //functional scope
num = "10" + 2;
console.log(num);


// Functions 
function Sum(a, b){
  console.log(a+b);
}
const Sum = function(a, b){
  console.log(a+b);
}

// Arrow function
const Sum = (a, b)=>{
  console.log(a+b);
}

Sum(5, 6);

// Loops
for(let a =0;a<10;a++){
  console.log(a);
}

// Objects
const user = {
  "id": 1001,
  "name": "John",
  "Class": "BTech",
  "Section": "9S417"
}

console.log(user);
console.log(user.name);

// Arrays
let arr = [1, 2, 3,4];
let strs = ["Phaham", "2.34", 3, 4];
console.log(arr);

const products = [
  {"name":"Puma", "quantity": 100, "price": 1999},
  {"name":"Sketchers", "quantity": 110, "price": 5999},
  {"name":"Nike", "quantity": 210, "price": 2999}
]

// TASK 1 - Extract all those shoes whose prices >= 2000 - filter
const higherPrice = products.filter(item => item.price >= 2000);
console.log(higherPrice);

// TASK 2 - Extract all shoe company names only
const companies = products.map(item=>item.name);
console.log(companies);

// TASK 3 - summation of all elements of an array
let numbers = [1, 2, 3, 4, 5, 6, 7, 8];
const sum = numbers.reduce((acc, currValue)=>{
  return acc + currValue;
}, 0)

console.log(sum);


// closures
function Evaluate(){
  let count = 0;
  return function(){
    count++;
    console.log(count);
  }
}

const counter = Evaluate();
counter();
counter();
counter();

// for(let i = 0;i<3;i++) {
//   console.log(counter());
// }

// Stringify & Parsing
const user1 = {
  "id": 100,
  "name": "John"
}
const objtoStr = JSON.stringify(user1);
console.log(objtoStr);

const strToObj = JSON.parse(objtoStr);
console.log(strToObj);


// TASK - Design a counter application

// blocking behaviour
const count = ()=>{
  console.log("strating a function");
  let count = 0;
  for(let a=0;a<10000000000;a++){
    count++;
  }
  console.log(count);
  console.log("Ending of function");
}
count();

// Promises - 
const fetchData = ()=>{
  return new Promise ((resolve, reject)=>{
    const dataFound = true;
    setTimeout(()=>{
      if(dataFound){
        resolve({"id": 100, "name": "Phaham"})
      }else{
        reject("Data Not Found")
      }
    }, 2000)
  })
}

fetchData().then(data=>console.log(data))
.catch(err=>console.log(err))
.finally(console.log("Task Completed"))

// Async Await
async function getUser(){
  try{
    const data = await fetchData();
    console.log(data); 
  }catch(err){
    console.error(err);
  }finally{
    console.log("Task Completed");
  }
}
getUser();

// Template Literals
const courses = {
  "title": "DevOps",
  "price": 1299
}

console.log(`Course ${courses.title} has price ${courses.price}`);

// Destructuring
const {title, price} = courses;
console.log("title: ",title);
console.log("price: ", price);

// Spread Operator
const newCourse = {...courses, "price": 599}
console.log(newCourse);

// Rest
function Sum(...arr){
  arr.reduce((acc, currValue)=>{
    return acc + currValue;
  }, 0)
}
Sum(10, 20, 30);

// Hoisting
helloworld();
function helloworld(){ 
  console.log("Hello world")
}