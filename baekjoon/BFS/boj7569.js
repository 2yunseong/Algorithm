class Queue {
  list = [];
  left = 0;
  length = 0;
  enQ(value) {
    this.list.push(value);
    this.length += 1;
  }
  deQ() {
    if (!this.length) return null;
    this.left += 1;
    this.length -= 1;
    return this.list[this.left - 1];
  }
}

const input = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const [condition, ...data] = require('fs')
  .readFileSync(input)
  .toString()
  .trim()
  .split('\n');

const [m, n, h] = condition.split(' ').map(Number);
const rowData = data.map((d) => d.split(' ').map(Number));
const board = [];
const visited = Array.from({ length: h }, () =>
  Array.from({ length: n }, () => Array.from({ length: m }, () => 0))
);

for (let i = 0; i < h; i++) {
  const temp = [];
  for (let j = 0; j < n; j++) {
    const t = rowData.shift();
    temp.push(t);
  }
  board.push(temp);
}

const Ipos = [0, 0, 1, -1, 0, 0];
const Jpos = [1, -1, 0, 0, 0, 0];
const Hpos = [0, 0, 0, 0, 1, -1];

function isValidRange(i, j, k) {
  return i >= 0 && i < n && j >= 0 && j < m && k >= 0 && k < h;
}

const q = new Queue();

for (let k = 0; k < h; k++) {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (visited[k][i][j] === 0 && board[k][i][j] === 1) {
        q.enQ([k, i, j]);
        visited[k][i][j] = 1;
      }
    }
  }
}

while (q.length) {
  const [k, i, j] = q.deQ();

  for (let v = 0; v < 6; v++) {
    const newH = k + Hpos[v];
    const newI = i + Ipos[v];
    const newJ = j + Jpos[v];

    if (
      isValidRange(newI, newJ, newH) &&
      visited[newH][newI][newJ] === 0 &&
      board[newH][newI][newJ] !== -1
    ) {
      visited[newH][newI][newJ] = 1;
      board[newH][newI][newJ] = board[k][i][j] + 1;
      q.enQ([newH, newI, newJ]);
    }
  }
}
const answerBoard = board.flat(Infinity);

if (answerBoard.filter((e) => e === 0).length !== 0) {
  console.log(-1);
} else {
  console.log(
    answerBoard.reduce((acc, cur) => (acc < cur ? cur : acc), -100) - 1
  );
}
