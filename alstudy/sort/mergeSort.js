function merge(a, b) {
  const results = [];
  let left = 0;
  let right = 0;

  while (left < a.length && right < b.length) {
    if (a[left] < b[right]) {
      results.push(a[left++]);
    } else {
      results.push(b[right++]);
    }
  }

  while (left < a.length) {
    results.push(a[left++]);
  }

  while (right < b.length) {
    results.push(b[right++]);
  }

  return results;
}

function mergeSort(arr) {
  // base condition : if arr length is 1, stop divide
  if (arr.length === 1) return arr;
  // 0~4 -> mid = 2
  const mid = Math.floor(arr.length / 2);
  // slice [0, mid) [mid, length)
  const left = arr.slice(0, mid);
  const right = arr.slice(mid);

  return merge(mergeSort(left), mergeSort(right));
}

console.log(mergeSort([6, 3, 8, 2, 7, 4]));

const arr = [6, 3, 2, 3, 8, 4, 1];

function mergeSort2(begin, end) {
  // [start, end) 가 1일 때
  if (end - begin <= 1) return begin;
  const mid = Math.floor((end + begin) / 2);

  console.log(begin, end);
  return merge2(mergeSort2(begin, mid), mergeSort2(mid, end));
}

function merge2(begin, end) {
  const mid = Math.floor((end + begin) / 2);
  const results = [];
  let left = begin;
  let right = mid;
  while (left < mid && right < end) {
    if (arr[left] < arr[right]) {
      results.push(arr[left++]);
    } else {
      results.push(arr[right++]);
    }
  }

  while (left < mid) {
    results.push(arr[left++]);
  }
  while (right < end) {
    results.push(arr[right++]);
  }

  for (let i = begin; i < end; i++) {
    arr[i] = results[i - begin];
  }

  let output = '';
  for (let i = begin; i < end; i++) {
    output += arr[i] + ' ';
  }

  console.log('compare:', arr);
  console.log('sort:', results);
}

mergeSort2(0, 7);
console.log(arr);
