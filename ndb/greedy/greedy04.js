const fs = require("fs");
const input = fs.readFileSync("./test.txt").toString().trim().split("\n");

const n = +input[0];
const coins = input[1]
  .split(" ")
  .map((e) => +e)
  .sort((a, b) => a - b);

let target = 1;

for (i of coins) {
  if (target < i) break;
  target += i;
}

console.log(target);
