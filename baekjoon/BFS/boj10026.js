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

let bSector = 0;
let sector = 0;
const visited = Array.from({ length: side }, () =>
  Array.from({ length: side }, () => 0)
);

const pureVisited = Array.from({ length: side }, () =>
  Array.from({ length: side }, () => 0)
);

function isVRange(i, j) {
  return i >= 0 && j >= 0 && i < side;
}

// blind Range
for (let i = 0; i < side; i++) {
  for (let j = 0; j < side; j++) {
    if (isVRange(i, j) && visited[i][j] === 0) {
      const bQ = new Queue();
      const initChar = blindBoard[i][j];
      bQ.enQ([i, j]);
      visited[i][j] = 1;
      while (bQ.length) {
        const [curI, curJ] = bQ.deQ();

        for (let v = 0; v < 4; v++) {
          const newI = curI + posI[v];
          const newJ = curJ + posJ[v];

          if (
            isVRange(newI, newJ) &&
            visited[newI][newJ] === 0 &&
            blindBoard[newI][newJ] === initChar
          ) {
            visited[newI][newJ] = 1;
            bQ.enQ([newI, newJ]);
          }
        }
      }
      bSector += 1;
    }
  }
}

for (let i = 0; i < side; i++) {
  for (let j = 0; j < side; j++) {
    if (isVRange(i, j) && pureVisited[i][j] === 0) {
      const q = new Queue();
      const initChar = board[i][j];
      q.enQ([i, j]);
      pureVisited[i][j] = 1;
      while (q.length) {
        const [curI, curJ] = q.deQ();

        for (let v = 0; v < 4; v++) {
          const newI = curI + posI[v];
          const newJ = curJ + posJ[v];

          if (
            isVRange(newI, newJ) &&
            pureVisited[newI][newJ] === 0 &&
            board[newI][newJ] === initChar
          ) {
            pureVisited[newI][newJ] = 1;
            q.enQ([newI, newJ]);
          }
        }
      }
      sector += 1;
    }
  }
}

console.log(`${sector} ${bSector}`);
