const input = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const [n, ...students] = require('fs')
  .readFileSync(input)
  .toString()
  .trim()
  .split('\n');

let order = 1;

for (let i = students[0].length - 1; i >= 0; i--) {
  const t = new Set(students.map((s) => s.slice(i)));
  if (t.size == +n) break;
  order++;
}

console.log(order);
