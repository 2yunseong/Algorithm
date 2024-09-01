const input = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim();

const R = 10;

console.log(
  input
    .split('') // 문자열을 배열로 변환한다.
    /* 카운트를 센다 */
    .reduce(
      (acc, cur) => {
        acc[+cur] += 1;
        return acc;
      },
      Array.from({ length: R }, (_) => 0)
    )
    /* 순서를 역으로 돌린다. */
    .reverse()
    /* 카운트 만큼 문자열을 생성한 이후, concat한다. */
    .reduce((acc, cur, idx) => {
      if (cur === 0) return acc;
      return acc + (R - idx - 1).toString().repeat(cur);
    }, '')
);
