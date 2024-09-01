const fs = require('fs');
const path = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const inputs = fs.readFileSync(path).toString().trim().split('\n');
const N = +inputs[0];
const M = +inputs[1];
const materials = inputs[2]
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);

let answer = 0;
let left = 0;
let right = N - 1;

while (left < right) {
  if (materials[left] + materials[right] === M) {
    answer++;
    left++;
    right--;
  } else if (materials[left] + materials[right] < M) {
    left++;
  } else if (materials[left] + materials[right] > M) {
    right--;
  }
}

console.log(answer);
