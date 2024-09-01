const [n, ...arr] = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

let answer = 0;
// 현재 인덱스의 위치정보를 저장한다. O(n)
const newArr = arr.map((value, idx) => ({
  idx,
  value,
}));

// 정렬한다. O(nlogn)
newArr.sort((a, b) => a.value - b.value);

// 정렬된 이후 인덱스와 이전 인덱스를 비교하고, 가장 많이 떨어진 값을 구한다.
newArr.forEach((element, curIdx) => {
  // 작은 값은 항상 왼쪽으로 이동한다. 큰 값은 오른쪽으로 이동하므로 음수의 값을 가진다.
  // 우리는 가장 작은 값이 왼쪽으로 얼마나 이동한지만 알면 된다.
  // 이 때 가장 작은 값이 무엇인지 알 필요없이 가장 많이 이동한 것이 가장 많은 gap을 가지므로 전체 탐색하여 풀어주면된다.
  const gap = element.idx - curIdx;
  answer = Math.max(answer, gap);
});

console.log(answer + 1);
