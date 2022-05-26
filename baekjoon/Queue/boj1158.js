const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().trim();

const inputArr = input.split(' ');
const n = parseInt(inputArr[0]);
const k = parseInt(inputArr[1]);
const que = [];
const answer = [];
let result = "";
for(let i =1; i<n+1; i++){
    que.push(i);
}

let count = 1;
while(que.length !== 0){
    if(count === k){
        answer.push(que.shift());
        count = 1;
    } else{
        count++;
        que.push(que.shift());
    }
}

result = "<" + answer.join(", ") + ">";
console.log(result);