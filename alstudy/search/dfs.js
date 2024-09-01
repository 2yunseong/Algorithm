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
    const target = this.sp - 1;
    this.sp--;
    return this.list[target];
  }
  push(value) {
    this.list[this.sp++] = value;
  }
  peek() {
    if (this.isEmpty()) return;
    return this.list[this.sp - 1];
  }
}

function dfs(graph, start, visited) {
  const stk = new Stack();
  stk.push(start);
  visited[start] = true;
  while (stk.size()) {
    const v = stk.pop();
    console.log(v);

    for (const node of graph[v]) {
      if (!visited[node]) {
        stk.push(node);
        visited[node] = true;
      }
    }
  }
}

const graph = [[1, 2, 4], [0, 5], [0, 5], [4], [0, 3], [1, 2]];
const visited = Array.from({ length: 6 }, () => false);

dfs(graph, 0, visited);
