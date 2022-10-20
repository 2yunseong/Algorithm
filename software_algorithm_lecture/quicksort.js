function quicksort(arr) {
  if (arr.length < 2) {
    return arr;
  }
  const pivot = [arr[0]];
  const left = [];
  const right = [];
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] < pivot[0]) {
      left.push(arr[i]);
    } else if (arr[i] > pivot[0]) {
      right.push(arr[i]);
    } else {
      pivot.push(arr[i]);
    }
  }

  return [...quicksort(left), ...pivot, ...quicksort(right)];
}

const array = [3, 5, 7, 1, 10, 9, 2];

console.log(quicksort(array), array.length);
