const N = +require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim();

const arr = Array.from({ length: N }, (_, i) => i + 1);

let isRemove = true;

while (arr.length > 1) {
  const element = arr.shift();
  if (!isRemove) {
    arr.push(element);
    isRemove = true;
  } else {
    isRemove = false;
  }
}

console.log(arr[0]);
