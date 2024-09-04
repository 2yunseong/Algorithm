const inputs = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');

const [n, ...tuples] = inputs;

const times = [];

let answer = [];

for (let i = 0; i < tuples.length; i++) {
  const [start, end] = tuples[i].split(' ').map(Number);
  times.push({ id: i, start, end, time: end - start });
}

times.sort((a, b) => a.time - b.time);

const maxTime = times.reduce((acc, cur) => Math.max(acc, cur.end), 0);

const reserved = new Array(maxTime + 1).fill(false);

times.forEach((e) => {
  const ts = getTimes(e.start, e.end);
  if (isReserve(ts)) {
  } else {
    answer.push(e);
    reserve(ts);
  }
});

console.log(answer);
function isReserve(arr) {
  for (let i = 0; i < arr.length; i++) {
    if (reserved[arr[i]]) return true;
  }
  return false;
}

function getTimes(start, end) {
  const result = [];
  for (let i = start; i < end; i++) {
    result.push(i);
  }
  return result;
}

function reserve(ts) {
  for (let i = 0; i < ts.length; i++) {
    reserved[ts[i]] = true;
  }
}

function cancel(ts) {
  for (let i = 0; i < ts.length; i++) {
    reserved[ts[i]] = false;
  }
}
function getDuplicatedTime(target) {
  const result = [];
  answer.forEach((e) => {
    if (target.start > e.start) {
      if (target.start < e.end) {
        result.push(e);
      }
    } else if (target.start < e.start) {
      if (e.start < target.end) {
        result.push(e);
      }
    } else {
      if (e.start - e.end !== 0) {
        result.push(e);
      }
    }
  });

  return result;
}
