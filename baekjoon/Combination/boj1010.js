const input = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const [t, ...querys] = require('fs')
  .readFileSync(input)
  .toString()
  .trim()
  .split('\n');

const testCase = +t;
const qs = querys.map((s) => s.split(' ').map(Number));

const table = Array.from({ length: 31 }, () =>
  Array.from({ length: 31 }, () => 0)
);

table[0][0] = 1;

for (let i = 1; i <= 30; i++) {
  table[i][0] = 1;
  table[i][i] = 1;
}

for (let i = 2; i <= 30; i++) {
  for (let j = 1; j < i; j++) {
    table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
  }
}

qs.forEach((e) => {
  console.log(table[e[1]][e[0]]);
});
