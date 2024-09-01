const N = +require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim();

const arr = Array.from({ length: N }, (_, i) => i + 1);

class Queue {
  constructor(init) {
    this.arr = init;
    this.lptr = 0;
    this.rptr = init.length - 1;
    this.length = init.length;
  }

  enQ(v) {
    this.arr[++this.rptr] = v;
    this.length += 1;
  }

  deQ() {
    if (this.isEmpty()) return;
    this.length -= 1;
    return this.arr[this.lptr++];
  }

  isEmpty() {
    return this.length === 0;
  }
}

let isRemove = true;

const q = new Queue(arr);

while (q.length > 1) {
  const element = q.deQ();
  if (!isRemove) {
    q.enQ(element);
    isRemove = true;
  } else {
    isRemove = false;
  }
}

console.log(q.arr[q.lptr]);
