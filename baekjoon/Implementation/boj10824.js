const fs = require("fs");
const input = fs.readFileSync('./input.txt').toString().split(' ');

function solve(){
    
    const first = input[0] + input[1];
    const second = input[2] + input[3];

    console.log(parseInt(first) + parseInt(second));
}

solve();

