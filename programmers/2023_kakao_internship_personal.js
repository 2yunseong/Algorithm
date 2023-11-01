const scores = [0, 3, 2, 1, 0, 1, 2, 3];

// 점수가 같으면 사전 순
const keys = ['RT', 'CF', 'JM', 'AN'];

function solution(survey, choices) {
  const result = {
    R: 0,
    T: 0,
    C: 0,
    F: 0,
    J: 0,
    M: 0,
    A: 0,
    N: 0,
  };
  var answer = '';
  survey.forEach((s, i) => {
    const [disAgree, agree] = s.split('');
    // 선택지 조회
    // 비동의 선택지 일 경우
    if (choices[i] <= 3) {
      result[disAgree] += scores[choices[i]];
    } // 중도인 경우
    else if (choices[i] === 4) {
    } // 동의 선택지인 경우
    else if (choices[i] > 4) {
      result[agree] += scores[choices[i]];
    }
  });

  const afd = keys.map((key) => {
    const [a, b] = key.split('');
    if (result[a] >= result[b]) return a;
    else return b;
  });

  return afd.join('');
}
