const fs = require('fs');
const { readFile, writeFile } = fs.promises;

// Synchronous read, write - blocking behav

// const data = fs.readFileSync('file.txt', 'utf-8');
// console.log(data);

// fs.writeFileSync('output.txt', 'Writing file fron node.js')


// Async read/write

// async function file_system_js() {
//   try {
//     const data = await fs.readFile('file.txt', 'utf-8');
//     console.log(data);
//   } catch {
//     console.log("File not found")
//   }
// }
// file_system_js();

// filename - data.json
// content - {id: 1001, name: John}

// TASK 1 - write a data.json
// async function saveData(data){
//   await writeFile('data.json', JSON.stringify(data, null, 2));
// }
// saveData({"id":1001, "name":"John"});

// - Ensuring directory is there or not

// async function ensureDirectory(dir){
//   await fs.promises.mkdir(dir, {recursive: true});
// }
// ensureDirectory('./data/users')

// deletion of file
// async function deleteFile(filepath){
//   try{
//      await fs.promises.unlink(filepath);
//      return true;
//   }catch{
//     console.log("file not found")
//   }
// }

// deleteFile('./output.txt')


// TASK 2 - frequecy of fruits
/* 
banana 4
apple 3
mango 2
*/
/*
const data = fs.readFileSync('fruits.txt', 'utf-8').trim();
console.log(data);

const fruits = data.split(',');
let map = {};

for(let fruit of fruits){
  map[fruit] = (map[fruit] || 0) + 1; 
}

let result = "";
for(let key in map){
  result += `${key} ${map[key]}\n`
}
console.log(result);

// write in output
fs.writeFileSync('output.txt', result);
*/


// TASK 3 - count no of lines
const data = fs.readFileSync('lines.txt', 'utf-8').trim();
const lines = data.split('\n');
console.log(lines.length)

// TASK 4 - Remove duplicate lines

// TASK 5 - Find Highest Number