const readline = require('readline');
const rl = readline.createInterface({
  input:process.stdin,
  output: process.stdout,
});
rl.on('line',line =>{
  rl.close();
  const [a,b,c] = line.split('').map(v=>Number(v));
  console.log(a+b+c);
})