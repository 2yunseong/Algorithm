function solution(n, m, k, arr) {
  let answer = 0;
  let count = 0;
  arr.sort((a, b) => b - a);

  const first = arr[0];
  const second = arr[1];

  for (let i = 0; i < m; i++) {
    if (count < k) {
      answer += first;
      count += 1;
    } else {
      answer += second;
      count = 0;
    }
  }
  return answer;
}

console.log(solution(5, 8, 3, [2, 4, 5, 4, 6]));
