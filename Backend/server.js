const path = require('path');
const http = require('http');



const server = http.createServer((req, res)=>{
  // req
  console.log(`Method: ${req.method}`);
  console.log(`Method: ${req.url}`);
  
  // res
  res.end(JSON.stringify("Hello From Node.js"))
})

let PORT = 3000;
server.listen(PORT, ()=>{
  console.log("Server is live on 3000")
})
