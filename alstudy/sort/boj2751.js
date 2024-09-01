const [n, ...arr] = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

function quickSort(arr, min = 0, max = arr.length - 1) {
  const pivot = arr[min];
  let left = min;
  let right = max;

  while (left <= right) {
    while (arr[left] < pivot) {
      left++;
    }

    while (arr[right] > pivot) {
      right--;
    }

    if (left <= right) {
      const swap = arr[left];
      arr[left] = arr[right];
      arr[right] = swap;
      left++;
      right--;
    }
  }

  if (min < right) quickSort(arr, min, right);
  if (max > left) quickSort(arr, left, max);
  return arr;
}

const answers = quickSort(arr);

let answer = '';

answers.forEach((number) => {
  answer += number.toString() + '\n';
});

console.log(answer.trim());
