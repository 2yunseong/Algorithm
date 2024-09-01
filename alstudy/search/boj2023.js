const n = Number(
  require('fs')
    .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
    .toString()
    .trim()
);

function isPrime(number) {
  if (number === 1) return false;
  for (let i = 2; i * i <= number; i++) {
    if (number % i === 0) return false;
  }
  return true;
}

const firstN = [2, 3, 5, 7];
const restN = [1, 3, 5, 7, 9];

function includes(arr, target) {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === target) return true;
  }
  return false;
}

function search(n, depth, target) {
  // base condition 1: 1자리 처리
  if (n === 1 && depth === 1) {
    return includes(firstN, +target[depth - 1]) && isPrime(+target);
  }
  // base conditon 2: 마지막 자리일 때
  if (depth === n) {
    return includes(restN, +target[depth - 1]) && isPrime(+target);
  }

  // 첫번째 자리 확인
  if (depth === 1 && includes(firstN, +target[depth - 1])) {
    return search(n, depth + 1, target);
  }

  // 나머지 수 확인
  if (!includes(restN, +target[depth - 1])) {
    return false;
  }

  if (!isPrime(Number(target.slice(0, depth)))) {
    return false;
  }

  return search(n, depth + 1, target);
}

const begin = Math.pow(10, n - 1);
const end = Math.pow(10, n);
let answer = '';

for (let i = begin; i < end; i++) {
  const target = i.toString();
  if (search(n, 1, target)) {
    answer += '\n' + target;
  }
}

console.log(answer.trim());
