class Queue {
  constructor() {
    this.list = [];
    this.head = 0;
    this.tail = 0;
  }
  size() {
    return this.tail - this.head;
  }
  isEmpty() {
    return this.size() === 0;
  }
  pop() {
    if (this.isEmpty()) return undefined;
    return this.list[this.head++];
  }
  push(value) {
    this.list[this.tail++] = value;
  }
  front() {
    if (this.isEmpty()) return;
    return this.list[this.head];
  }
  back() {
    if (this.isEmpty()) return;
    return this.list[this.tail - 1];
  }
}

function BFS(graph, start, visited) {
  const queue = new Queue();
  queue.push(start);
  visited[start] = true;

  while (queue.size()) {
    const v = queue.pop();
    console.log(v);

    for (const node of graph[v]) {
      if (!visited[node]) {
        queue.push(node);
        visited[node] = true;
      }
    }
  }
}

const graph = [[1, 2, 4], [0, 5], [0, 5], [4], [0, 3], [1, 2]];
const visited = Array.from({ length: 6 }, () => false);

BFS(graph, 0, visited);
