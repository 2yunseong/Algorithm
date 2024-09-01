const inputs = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');

const [N, K] = inputs[0].trim().split(' ').map(Number);
const array = inputs[1].split(' ').map(Number);

function merge(a, b) {
  const results = [];
  let left = 0;
  let right = 0;

  // merge logic
  while (left < a.length && right < b.length) {
    if (a[left] < b[right]) {
      results.push(a[left++]);
    } else {
      results.push(b[right++]);
    }
  }
  // clean up aArr
  while (left < a.length) {
    results.push(a[left++]);
  }
  // clean up bArr
  while (right < b.length) {
    results.push(b[right++]);
  }

  return results;
}

function sort(arr) {
  // base condition : if arr.length 1, stop divide
  if (arr.length === 1) return arr;
  // floor is useful function to find mid index. because arr is based zero-idx
  const mid = Math.floor(arr.length / 2);
  // divide by mid idx
  const left = arr.slice(0, mid);
  const right = arr.slice(mid);

  // conquer by recursion call
  return merge(sort(left), sort(right));
}

console.log(sort(array)[K - 1]);
