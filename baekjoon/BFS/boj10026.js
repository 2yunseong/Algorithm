const input = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const [n, ...grid] = require('fs')
  .readFileSync(input)
  .toString()
  .trim()
  .split('\n');

const side = +n;
const board = grid.map((g) => g.split(''));

const RED = 'R';
const GREEN = 'G';
const BLUE = 'B';
const BLIND = 'Z';

const posI = [0, 0, 1, -1];
const posJ = [1, -1, 0, 0];

const blindBoard = board.map((rows) =>
  rows.map((e) => {
    if ((e === RED) | (e === GREEN)) return BLIND;
    return e;
  })
);

let bSector = 0;
let sector = 0;
const blindVisit = Array.from({ length: side }, () =>
  Array.from({ length: side }, () => 0)
);

const visit = Array.from({ length: side }, () =>
  Array.from({ length: side }, () => 0)
);

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

function isVRange(i, j) {
  return i >= 0 && j >= 0 && i < side;
}

function dfs(i, j, bor, vis) {
  const q = new Queue();
  const initChar = bor[i][j];
  q.enQ([i, j]);
  vis[i][j] = 1;
  while (q.length) {
    const [curI, curJ] = q.deQ();

    for (let v = 0; v < 4; v++) {
      const newI = curI + posI[v];
      const newJ = curJ + posJ[v];

      if (
        isVRange(newI, newJ) &&
        vis[newI][newJ] === 0 &&
        bor[newI][newJ] === initChar
      ) {
        vis[newI][newJ] = 1;
        q.enQ([newI, newJ]);
      }
    }
  }
}

for (let i = 0; i < side; i++) {
  for (let j = 0; j < side; j++) {
    if (isVRange(i, j) && visit[i][j] === 0) {
      dfs(i, j, board, visit);
      sector += 1;
    }
    if (isVRange(i, j) && blindVisit[i][j] === 0) {
      dfs(i, j, blindBoard, blindVisit);
      bSector += 1;
    }
  }
}

console.log(`${sector} ${bSector}`);
