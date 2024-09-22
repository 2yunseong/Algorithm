const inputs = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const MAX_LEN = 1000004;
const sieves = new Array(MAX_LEN).fill(true);

// 에라토스테네스의 체
for (let i = 2; i < sieves.length; i++) {
  if (sieves[i]) {
    for (let j = i + i; j < sieves.length; j += i) {
      sieves[j] = false;
    }
  }
}

let answer = '';  // 답이 될 문자열

const numbers = inputs.slice(0, inputs.length - 1); // 0은 종료 조건이므로 제외시킨다.

numbers.forEach((input) => {
  let isGoldBach = false; // 골드바흐 추측이 틀렸을 때,
  // 범위 지정. 반대편의 수를 빼줄 것이므로 MAX_LEN / 2 까지만 순회해도 됨
  for (let i = 3; i < MAX_LEN / 2; i++) {
    // i 도 소수, n-i 도 소수라면
    if (sieves[i] && sieves[input - i]) {
      isGoldBach = true;
      answer += `${input} = ${i} + ${input - i}\n`;
      break;
    }
  }
  if (!isGoldBach) {
    answer += "Goldbach's conjecture is wrong.\n";
  }
});

console.log(answer.trim());
