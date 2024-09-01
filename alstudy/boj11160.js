const fs = require('fs');
const path = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const inputs = fs.readFileSync(path).toString().trim().split('\n');
const [n, m] = inputs[0].split(' ').map(Number);

const graph = []; // 그래프

/* ---- 데이터 처리 로직 ---- */
const graphs = inputs.slice(1, 1 + n);
const poss = inputs.slice(1 + n);

graph.push(Array.from({ length: n }, () => 0));

graphs.forEach((e) => {
  const row = e.split(' ').map(Number);
  graph.push([0, ...row]);
});

/* ---- 데이터 처리 로직 ---- */

const sigmas = [];

// 메모이제이션 -> 점화식을 통한 초기화
for (let i = 0; i <= n; i++) {
  sigmas.push([]);
  for (let j = 0; j <= n; j++) {
    // 초기 조건 1
    if (i === 0 || j === 0) {
      sigmas[i][j] = 0;
    }
    // 초기 조건 2
    else if (i === 1 && j === 1) {
      sigmas[i][j] = graph[i][j];
    }
    // 첫번째 행일 경우
    else if (i === 1) {
      sigmas[i][j] = sigmas[i][j - 1] + graph[i][j];
    }
    // 첫번째 열일 경우
    else if (j === 1) {
      sigmas[i][j] = sigmas[i - 1][j] + graph[i][j];
    }
    // 나머지
    else {
      sigmas[i][j] =
        sigmas[i - 1][j] +
        sigmas[i][j - 1] +
        graph[i][j] -
        sigmas[i - 1][j - 1];
    }
  }
}
const answers = [];

/* m번만큼 반복한다. */
// Answer를 구하는 로직
poss.forEach((e) => {
  const [x1, y1, x2, y2] = e.split(' ').map(Number);
  answers.push(
    sigmas[x2][y2] +
      sigmas[x1 - 1][y1 - 1] -
      sigmas[x1 - 1][y2] -
      sigmas[x2][y1 - 1]
  );
});

console.log(answers.join('\n'));
