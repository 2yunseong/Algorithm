const queue = {
  list: [],
  head: 0, // 큐의 가장 앞을 가리키는 인덱스
  tail: 0, // 큐의 다음 push 값이 들어올 인덱스
  isEmpty() {
    return this.size() === 0;
  },
  push(value) {
    this.list[this.tail++] = value;
  },
  pop() {
    if (this.isEmpty()) return undefined;
    return this.list[this.head--];
  },
  front() {
    if (this.isEmpty()) return undefined;
    return this.list[this.head];
  },
  back() {
    if (this.isEmpty()) return undefined;
    return this.list[this.tail - 1];
  },
  size() {
    return this.tail - this.head;
  },
};

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
    return this.list[this.head--];
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
