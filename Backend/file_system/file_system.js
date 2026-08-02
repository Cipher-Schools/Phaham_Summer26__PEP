
// ---------
const fs = require('fs');
const {readFile, writeFile} = require('fs').promises;

const path  = require('path');

// Synchronous - blocking behav
// const filepath = path.join(__dirname, 'file.txt');
// const dataSync = fs.readFileSync(filepath, 'utf-8');
// console.log(dataSync);

// fs.writeFileSync('output.txt', 'Hello World')

// Async
// async function redingFile(){
//   try{
//   const data = await fs.readFile('file.txt', 'utf-8');
//   console.log(data);

//   // fs.writeFile('output.txt', 'Hello World');
//   }catch{
//     console.log("File not found")
//   }
// }


// async function saveData(data){
//   await writeFile('data.json', JSON.stringify(data, null, 2));
// }
// saveData({"id":1001, "name":"John"})

// check directory
// async function validateDir(dir){
//   await fs.promises.mkdir(dir, {recursive: true})
// }

// validateDir('./data/users')

// delete a file
// async function deleteFile(filepath){
//   try{
//     await fs.promises.unlink(filepath)
//     return true;
//   }catch{
//     console.log("file not found");
//   }
// }
// deleteFile('./data.json')



// TASK 1 - Frquency of fruits
// const filePath = path.join(__dirname, 'fruits.txt');
// const data = fs.readFileSync(filePath, 'utf-8').trim();
// const fruits = data.split(',')
// const map = {};

// for(const fruit of fruits){
//   map[fruit] = (map[fruit] || 0)+1;
// }

// let result = "";
// for(key in map){
//   result += `${key} ${map[key]}\n`
// }
  
// fs.writeFileSync('output.txt', result.trim());


// TASK 2 - No of lines in a file
// const filePath = path.join(__dirname, 'lines.txt');
// const data = fs.readFileSync(filePath, 'utf-8').trim().toString();
// let lines = data.split('\n');
// console.log(lines.length)



// TASK 3 - Remove duplicate lines

// TASK 4 - Find Highest Number