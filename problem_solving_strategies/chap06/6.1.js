// 코드 6.1 1부터 n까지 합을 계산하는 코드
// 필수 조건 : n >= 1
// 결과 : 1부터 n까지의 합을 반환한다.

function sum(n) {
  let ret = 0;
  for (let i = 1; i <= n; i++) {
    ret += i;
  }
  return ret;
}

function recursiveSum(n) {
  // 기저 사례 : n == 1 일 때
  if (n == 1) return 1;
  // n이 1보다 클 때
  return recursiveSum(n - 1) + n;
}

console.log("sum(5)", sum(5));
console.log("recursiveSum(5)", recursiveSum(5));
