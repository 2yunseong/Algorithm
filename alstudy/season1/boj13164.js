const [nk, arr] = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');

const [n, k] = nk.split(' ').map(Number);
const children = arr.split(' ').map(Number);
// 1일 경우, 답은 무조건 0이다.
if (children.length < 1) {
  console.log(0);
} else {
  const gap = []; // 옆사람과의 키 차이를 저장할 배열
  // 키 차이를 구하는 로직
  for (let i = 0; i < children.length - 1; i++) {
    const large = children[i + 1];
    const small = children[i];
    gap.push(large - small);
  }
  // 정렬
  gap.sort((a, b) => a - b);
  // 뒤에서부터 k-1개를 짜른다.
  for (let i = 1; i < k; i++) {
    gap.pop();
  }

  // 합을 계산 후 출력
  console.log(gap.reduce((acc, cur) => acc + cur, 0));
}
