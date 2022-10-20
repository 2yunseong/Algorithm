function selectionAlgorithm(arr, k) {
  const pivot = [arr[0]];
  const left = [];
  const right = [];
  let answer = -1;
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] < pivot[0]) {
      left.push(arr[i]);
    } else if (arr[i] > pivot[0]) {
      right.push(arr[i]);
    } else {
      pivot.push(arr[i]);
    }
  }

  const s = left.length;
  if (k <= s) {
    return selectionAlgorithm(left, k);
  } else if (k === s + 1) {
    return pivot[0];
  } else if (k > s + 1) {
    k = k - s - 1;
    return selectionAlgorithm(right, k);
  }
}

const k = 9;
const arr = [6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14];

console.log(selectionAlgorithm(arr, k));
