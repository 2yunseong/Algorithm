const inputs = require('fs')
  .readFileSync(
    process.platform === 'linux' ? '/dev/stdin' : './input.txt',
    'utf8'
  )
  .toString()
  .trim()
  .split('\n');

const p = inputs[1].split(' ').map(Number);
p.sort((a, b) => a - b);

console.log(
  p.reduce((acc, _, idx) => {
    let cur = 0;
    for (let i = 0; i <= idx; i++) {
      cur += p[i];
    }
    return acc + cur;
  }, 0)
);
