const inputs = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');

const k = +inputs[0].split(' ')[1];
const temperates = inputs[1].split(' ').map(Number);

let answer = -Number.MAX_SAFE_INTEGER;

for (let i = 0; i < temperates.length - (k - 1); i++) {
  let acc = 0;
  let start = i;
  let end = i + k;
  for (let j = start; j < end; j++) {
    acc += temperates[j];
  }
  answer = Math.max(acc, answer);
}

console.log(answer);
