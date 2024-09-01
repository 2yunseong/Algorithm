const inputs = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');
const [n, m] = inputs[0].split(' ').map(Number);
const arr = []; // 미로 2차원 배열
const visited = []; // 방문한 정보를 기록할 2차원 배열
// 미로를 2차원 배열로 변경한다.
for (let i = 1; i < inputs.length; i++) {
  const parsed = inputs[i].trim().split('').map(Number);
  arr.push(parsed);
  visited.push(Array.from({ length: parsed.length }, () => 0));
}

// Queue 구현 코드
class Queue {
  constructor() {
    this.list = [];
    this.start = 0;
    this.end = 0;
  }
  size() {
    return this.end - this.start;
  }
  isEmpty() {
    return this.size() === 0;
  }
  push(value) {
    this.list[this.end++] = value;
  }
  pop() {
    if (this.isEmpty()) return;
    return this.list[this.start++];
  }
}

// 배열을 벗어나지는 않는지 검사하는 함수
function isInBoundary(r, c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

// 벽이 아닌지 검사하는 함수
function isAbleArea(r, c) {
  return arr[r][c] === 1;
}

const q = new Queue();
const initPos = { x: 0, y: 0, v: 1 };

q.push(initPos);
visited[0][0] = 1;

// 방향을 나타내는 인덱스
const xPos = [0, 0, 1, -1];
const yPos = [-1, 1, 0, 0];

while (q.size()) {
  const pos = q.pop();

  for (let i = 0; i < 4; i++) {
    const x = pos.x + xPos[i];
    const y = pos.y + yPos[i];

    if (isInBoundary(x, y) && isAbleArea(x, y) && visited[x][y] === 0) {
      q.push({ x, y, v: pos.v + 1 });
      visited[x][y] = pos.v + 1;
    }
  }
}

console.log(visited[n - 1][m - 1]);
