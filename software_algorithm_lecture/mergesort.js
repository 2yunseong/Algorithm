const arr = [6, 1, 14, 2, 20, 29, 18, 15, 45, 30, 25];
const newArr = new Array(arr.length).fill(0);

function merge(left, right) {
  let array = [];

  while (left.length && right.length) {
    if (left[0] < right[0]) {
      array.push(left.shift());
    } else {
      array.push(right.shift());
    }
  }

  return [...array, ...left, ...right];
}

function mergeSort(array) {
  const center = array.length / 2;
  if (array.length < 2) {
    return array;
  }
  const leftArr = array.splice(0, center);
  return merge(mergeSort(leftArr), mergeSort(array));
}

console.log(mergeSort(arr));
