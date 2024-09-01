const inputs = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');
const [n, m, V] = inputs[0].trim().split(' ').map(Number);
const graph = {};
for (let i = 1; i < inputs.length; i++) {
  const [start, end] = inputs[i].trim().split(' ').map(Number);
  if (!graph[start] && !graph[end]) {
    graph[start] = [end];
    graph[end] = [start];
  } else if (!graph[start] && !!graph[end]) {
    graph[start] = [end];
    graph[end] = [...graph[end], start];
  } else if (!!graph[start] && !graph[end]) {
    graph[start] = [...graph[start], end];
    graph[end] = [start];
  } else {
    graph[start] = [...graph[start], end];
    graph[end] = [...graph[end], start];
  }
}

class Queue {
  constructor() {
    this.list = [];
    this.head = 0;
    this.tail = 0;
  }
  isEmpty() {
    return this.size() === 0;
  }
  size() {
    return this.tail - this.head;
  }
  push(value) {
    this.list[this.tail++] = value;
  }
  pop() {
    if (this.isEmpty()) return;
    return this.list[this.head++];
  }
}

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
  push(value) {
    this.list[this.sp++] = value;
  }
  pop() {
    if (this.isEmpty()) return;
    return this.list[--this.sp];
  }
}

function search(container, graph, start, visited) {
  const answer = [];
  container.push(start);
  visited[start] = true;

  while (container.size()) {
    const v = container.pop();
    answer.push(v);
    if (!graph[v]) return answer;
    for (const node of graph[v]) {
      if (!visited[node]) {
        container.push(node);
        visited[node] = true;
      }
    }
  }
  return answer;
}

function dfs(container, graph, start, visited) {
  const answer = [];
  container.push(start);

  while (container.size()) {
    const v = container.pop();
    if (!visited[v]) {
      answer.push(v);
      visited[v] = true;
      if (!graph[v]) return answer;
      for (const node of graph[v]) {
        container.push(node);
      }
    }
  }

  return answer;
}
const dVisit = Array.from({ length: n + 1 }, () => false);
const bVisit = Array.from({ length: n + 1 }, () => false);

for (const property in graph) {
  graph[property].sort((a, b) => b - a);
}
const dfsAnswer = dfs(new Stack(), graph, V, dVisit);
for (const property in graph) {
  graph[property].sort((a, b) => a - b);
}
const bfsAnswer = search(new Queue(), graph, V, bVisit);

if (dfsAnswer.length === 0) {
  console.log(V);
} else {
  console.log(dfsAnswer.join(' '));
}
if (bfsAnswer.length === 0) {
  console.log(V);
} else {
  console.log(bfsAnswer.join(' '));
}
