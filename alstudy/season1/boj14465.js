const inputs = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');

const [N, K, B] = inputs[0].split(' ').map(Number);

const brokens = inputs.slice(1).map(Number);

brokens.sort((a, b) => a - b);

let answer = 999999; // 최대값으로 지정한다.

if (!brokens.length) {
  // 고칠 신호등이 없으면 답은 0이다.
  console.log(0);
} else {
  for (let start = 1; start <= N - (K - 1); start++) {
    const end = start + K - 1;
    let count = 0;
    for (let idx = 0; idx < brokens.length; idx++) {
      if (start <= brokens[idx] && brokens[idx] <= end) {
        count++;
      }
      // End보다 크면 더 검사해줄 필요가 없다.
      else if (brokens[idx] > end) {
        break;
      }
    }
    // 최소로 고장난 신호등을 고치는 횟수를 갱신한다.
    answer = Math.min(answer, count);
  }
  console.log(answer);
}
