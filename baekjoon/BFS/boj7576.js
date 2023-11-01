// https://www.acmicpc.net/problem/7576
const input = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

const [mn, ...grid] = require('fs')
  .readFileSync(input)
  .toString()
  .trim()
  .split('\n');

const [m, n] = mn.split(' ').map(Number);
const board = grid.map((i) => i.split(' ').map(Number));
const visited = Array.from({ length: n }, () =>
  Array.from({ length: m }, () => 0)
);

class Queue {
  list = [];
  left = 0;
  length = 0;

  enqueue(value) {
    this.list.push(value);
    this.length += 1;
  }
  dequeue() {
    if (!this.length) return null;
    this.left += 1;
    this.length -= 1;
    return this.list[this.left - 1];
  }
}

class Point {
  constructor(i, j) {
    this.i = i;
    this.j = j;
  }
}

const WALL = -1;
const SPACE = 0;
const TOMATO = 1;
const Ipos = [0, 0, 1, -1];
const Jpos = [1, -1, 0, 0];
let isValid = true;
let max = -1;

const isValidIndexRange = (i, j) => {
  return i >= 0 && i < n && j >= 0 && j < m;
};

const q = new Queue();

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (board[i][j] === TOMATO) {
      q.enqueue(new Point(i, j));
      visited[i][j] = 1;
    }
  }
}

while (q.length) {
  const cur = q.dequeue();

  for (let t = 0; t < 4; t++) {
    const curI = cur.i + Ipos[t];
    const curJ = cur.j + Jpos[t];

    if (!isValidIndexRange(curI, curJ)) continue;
    if (visited[curI][curJ] === 0 && board[curI][curJ] !== WALL) {
      q.enqueue(new Point(curI, curJ));
      board[curI][curJ] += board[cur.i][cur.j] + 1;
      visited[curI][curJ] = 1;
    }
  }
}
// 0인지 체크
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (board[i][j] === SPACE) {
      isValid = false;
      break;
    }
  }
}

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (max < board[i][j]) {
      max = board[i][j];
    }
  }
}

if (!isValid) {
  console.log(-1);
} else {
  console.log(max - 1);
}
