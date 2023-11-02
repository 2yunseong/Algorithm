class Queue {
  l = [];
  len = 0;
  left = 0;
  eQ(v) {
    this.l.push(v);
    this.len += 1;
  }
  dQ() {
    if (!this.len) return null;
    this.left += 1;
    this.len -= 1;
    return this.l[this.left - 1];
  }
}
const input = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const [t, ...data] = require('fs')
  .readFileSync(input)
  .toString()
  .trim()
  .split('\n');

const testCase = +t;
const inputDatas = [];
const Ipos = [-2, -2, -1, -1, 1, 1, 2, 2];
const Jpos = [1, -1, 2, -2, 2, -2, 1, -1];

for (let i = 0; i < testCase; i++) {
  const size = +data.shift();
  const from = data.shift().split(' ').map(Number);
  const dest = data.shift().split(' ').map(Number);
  inputDatas.push({
    size,
    from,
    dest,
  });
}

function isValidRange(i, j, s) {
  return i >= 0 && i < s && j >= 0 && j < s;
}

for (let e = 0; e < testCase; e++) {
  const { size, from, dest } = inputDatas[e];
  const [destI, destJ] = dest;
  let answer = 0;

  const board = Array.from({ length: size }, () =>
    Array.from({ length: size }, () => 0)
  );
  const visited = Array.from({ length: size }, () =>
    Array.from({ length: size }, () => 0)
  );

  const q = new Queue();
  board[from[0]][from[1]] = 0;
  q.eQ([...from]);
  visited[from[0]][from[1]] = 1;

  while (q.len) {
    const [i, j] = q.dQ();
    if (i === destI && j === destJ) {
      answer = board[i][j];
      break;
    }
    for (let v = 0; v < 9; v++) {
      const newI = i + Ipos[v];
      const newJ = j + Jpos[v];

      if (isValidRange(newI, newJ, size) && visited[newI][newJ] === 0) {
        board[newI][newJ] = board[i][j] + 1;
        visited[newI][newJ] = 1;
        q.eQ([newI, newJ]);
      }
    }
  }

  console.log(answer);
}
