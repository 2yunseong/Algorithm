const { array, func } = require('prop-types');

function quickSort(arr) {
  if (arr.length < 2) return arr;
  const pivot = arr[0];
  const left = [];
  const right = [];

  for (let i = 1; i < arr.length; i++) {
    if (pivot > arr[i]) {
      left.push(arr[i]);
    } else {
      right.push(arr[i]);
    }
  }

  return [...quickSort(left), pivot, ...quickSort(right)];
}

function qs_Inplace(arr, min = 0, max = arr.length - 1) {
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
      const temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;
      left++;
      right--;
    }
  }

  if (min < right) qs_Inplace(arr, min, right);
  if (max > left) qs_Inplace(arr, left, max);
  return arr;
}

function foo(arr, min = 0, max = arr.length - 1) {
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

  if (min < right) foo(arr, min, right);
  if (max > left) foo(arr, left, max);
  return arr;
}

console.log(qs_Inplace([4, 6, 7, 3, 5, 1, 2]));
console.log(foo([4, 6, 7, 3, 5, 1, 2]));
