

const http = require('http');
const server = http.createServer((req, res)=>{
  // req
  console.log("URL", `${req.url}`)

  // res
  res.end(JSON.stringify("Hello From Node.js"))
})

let PORT = 3000;
server.listen(PORT, ()=>{
  console.log(`Server started at ${PORT}`)
})

