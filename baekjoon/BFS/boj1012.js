const input = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const [t, ...info] = require('fs')
  .readFileSync(input)
  .toString()
  .trim()
  .split('\n');
const BACHU = 1;
const testCase = +t;
const cases = [];
const Ipos = [0, 0, 1, -1];
const Jpos = [1, -1, 0, 0];
let idx = 0;

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

for (let i = 0; i < t; i++) {
  let [w, h, count] = info[idx++].split(' ').map(Number);
  const places = [];
  while (count !== 0) {
    places.push(info[idx++].split(' ').map(Number));
    count--;
  }
  cases.push({
    width: w,
    height: h,
    places,
  });
}

function main() {
  for (let i = 0; i < testCase; i++) {
    let answer = 0;
    const { width, height, places } = cases[i];
    const board = Array.from({ length: height }, () =>
      Array.from({ length: width }, () => 0)
    );

    const visited = Array.from({ length: height }, () =>
      Array.from({ length: width }, () => 0)
    );

    places.forEach((p) => {
      board[p[1]][p[0]] = BACHU;
    });

    for (let i = 0; i < height; i++) {
      for (let j = 0; j < width; j++) {
        if (visited[i][j] === 0 && board[i][j] !== 0) {
          const q = new Queue();
          q.enqueue([i, j]);
          visited[i][j] = 1;
          while (q.length) {
            const [ii, jj] = q.dequeue();
            for (let k = 0; k < 4; k++) {
              const curI = ii + Ipos[k];
              const curJ = jj + Jpos[k];

              if (
                isValidRange(curI, curJ, height, width) &&
                visited[curI][curJ] === 0 &&
                board[curI][curJ] === 1
              ) {
                visited[curI][curJ] = 1;
                q.enqueue([curI, curJ]);
              }
            }
          }
          answer += 1;
        }
      }
    }
    console.log(answer);
  }
}

function isValidRange(i, j, height, width) {
  return i >= 0 && j >= 0 && i < height && j < width;
}

main();
