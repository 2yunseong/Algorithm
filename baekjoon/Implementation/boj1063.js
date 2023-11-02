// R : 한 칸 오른쪽으로
// L : 한 칸 왼쪽으로
// B : 한 칸 아래로
// T : 한 칸 위로
// RT : 오른쪽 위 대각선으로
// LT : 왼쪽 위 대각선으로
// RB : 오른쪽 아래 대각선으로
// LB : 왼쪽 아래 대각선으로
const input = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const [query, ...moves] = require('fs')
  .readFileSync(input)
  .toString()
  .trim()
  .split('\n');

const [king, stone, _] = query.split(' ');

const board = Array.from({ length: 8 }, () =>
  Array.from({ length: 8 }, () => 0)
);

const dir = {
  R: [1, 0],
  L: [-1, 0],
  B: [0, -1],
  T: [0, 1],
  RT: [1, 1],
  LT: [-1, 1],
  RB: [1, -1],
  LB: [-1, -1],
};

function transferAlphabet(char) {
  switch (char) {
    case 'A':
      return 0;
    case 'B':
      return 1;
    case 'C':
      return 2;
    case 'D':
      return 3;
    case 'E':
      return 4;
    case 'F':
      return 5;
    case 'G':
      return 6;
    case 'H':
      return 7;
  }
}

const AlphaTable = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'];

function changeIndex(param) {
  return param - 1;
}

function changeStrDirectToPair(str) {
  return str.split('').map((e, i) => {
    if (i == 0) return transferAlphabet(e);
    return changeIndex(e);
  });
}

function isValidRange(i, j) {
  return i >= 0 && i < 8 && j >= 0 && j < 8;
}
// 0 : Alpha 1: number
let Tking = changeStrDirectToPair(king);
let Tstone = changeStrDirectToPair(stone);

for (let i = 0; i < moves.length; i++) {
  const m = moves[i];
  const nextKingMove = [Tking[0] + dir[m][0], Tking[1] + dir[m][1]];
  // king이 나가는 경우 스킵한다.
  if (!isValidRange(nextKingMove[0], nextKingMove[1])) continue;
  // king이 움직일 자리에 돌이 있는 경우 밀어내는데
  if (nextKingMove[0] === Tstone[0] && nextKingMove[1] === Tstone[1]) {
    const nextStoneMove = [Tstone[0] + dir[m][0], Tstone[1] + dir[m][1]];
    if (!isValidRange(nextStoneMove[0], nextStoneMove[1])) continue;
    Tstone = [nextStoneMove[0], nextStoneMove[1]];
  }
  Tking = [nextKingMove[0], nextKingMove[1]];
}

console.log(`${AlphaTable[Tking[0]]}${Tking[1] + 1}`);

console.log(`${AlphaTable[Tstone[0]]}${Tstone[1] + 1}`);
