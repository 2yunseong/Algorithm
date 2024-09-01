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
