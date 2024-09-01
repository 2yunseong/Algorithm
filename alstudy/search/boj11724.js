const inputs = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');
const [N, M] = inputs[0].split(' ').map(Number);
const graph = {}; // 그래프를 선언한다.

class Stack {
  constructor() {
    this.list = [];
    this.sp = 0;
  }
  isEmpty() {
    return this.sp === 0;
  }
  size() {
    return this.sp;
  }
  pop() {
    if (this.isEmpty()) return;
    return this.list[--this.sp];
  }
  push(value) {
    this.list[this.sp++] = value;
  }
}
// 그래프를 초기화한다.
for (let i = 1; i <= N; i++) {
  graph[i] = [];
}

// 양방향 그래프 이므로 간선 정보를 양방향으로 그어주는데, 중복되는 간선이 들어오지는 않는다. 따라서 아래처럼 러프하게 작성가능하다.
for (let i = 1; i < inputs.length; i++) {
  const [start, end] = inputs[i].split(' ').map(Number);
  graph[start].push(end);
  graph[end].push(start);
}

let answer = 0; // 답이 될 변수: 연결요소의 갯수
const visited = Array.from({ length: N + 1 }, () => false); // 방문했는지를 나타낼 배열

// 모든 정점을 탐색한다.
for (let k = 1; k <= N; k++) {
  // 만약, 비어있다면 정점이 간선에 연결된 것이 없는 고립된 것이므로, 하나로 취급
  if (!graph[k]) {
    // 연결 요소가 한개 있으므로 더해주고,
    answer++;
    // visited는 true로 남겨주자.
    visited[k] = true;
    continue;
  }

  // 만약 방문한 정점이라면 건너 띄워준다.
  if (visited[k]) {
    continue;
  }

  // 전형적인 BFS 코드
  const s = new Stack();
  s.push(k);
  visited[k] = true;
  while (s.size()) {
    const v = s.pop();

    for (const node of graph[v]) {
      if (!visited[node]) {
        s.push(node);
        visited[node] = true;
      }
    }
  }

  answer += 1;
}

console.log(answer);
