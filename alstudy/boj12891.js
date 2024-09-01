const [sp, input, map] = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');

const [s, p] = sp.split(' ').map(Number);
const requirement = map.split(' ').map(Number);
const dp = Array.from({ length: s - p + 1 });

// 데이터 입력

// 비밀번호 조건을 충족하는지 테스트하는 함수
function isMatch(target, test) {
  let flag = true;
  for (let i = 0; i < test.length; i++) {
    if (test[i] - target[i] > 0) {
      flag = false;
      break;
    }
  }

  return flag;
}

// 각 글자별 인덱스 부여
const A = 0;
const C = 1;
const G = 2;
const T = 3;

// 카운팅을 세는 배열에서 해당 문자의 카운팅 횟수를 뺀 배열을 리턴
function removeCount(arr, char) {
  const result = [...arr];
  switch (char) {
    case 'A':
      result[A] -= 1;
      break;
    case 'C':
      result[C] -= 1;
      break;
    case 'G':
      result[G] -= 1;
      break;
    case 'T':
      result[T] -= 1;
      break;
  }
  return result;
}

// 카운팅을 세는 배열에서 해당 문자의 카운팅 횟수를 더힌 베열을 리턴
function incrementCount(arr, char) {
  const result = [...arr];
  switch (char) {
    case 'A':
      result[A] += 1;
      break;
    case 'C':
      result[C] += 1;
      break;
    case 'G':
      result[G] += 1;
      break;
    case 'T':
      result[T] += 1;
      break;
  }
  return result;
}

// dp[0], 즉 초기요소는 수동으로 선언 및 할당해주어야 한다.
let curIdx = 0;

// 답으로 출력할 변수
let answer = 0;

// 첫번째 요소의 카운팅 배열
let initMap = [0, 0, 0, 0];

// dp[0]를 구해야 다음 d[1], d[2]를 점화식을 통해 구할 수 있다.
// 아래는 그 로직이다.
for (let i = curIdx; i < p; i++) {
  initMap = incrementCount(initMap, input[i]);
}

dp[curIdx] = [...initMap];

// dp는 최대 s - p + 1 개를 가진다.
for (let i = 0; i < s - p + 1; i++) {
  // 1. 매칭 되는지 검사한다.
  if (isMatch(dp[i], requirement)) {
    answer += 1;
  }
  // 2. 이전 것을 제외하고,
  initMap = removeCount(initMap, input[i]);
  // 3. 다음의 새로운 값을 넣는다.
  initMap = incrementCount(initMap, input[p + i]);
  // 3. 새로 저장한다.
  dp[i + 1] = [...initMap];
}

console.log(answer);
