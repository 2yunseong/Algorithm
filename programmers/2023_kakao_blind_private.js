const MONTH = 28;
const SPACE = ' ';
const STANDARD_YEAR = 2000;

// YYYY.MM.DD
const transformDateToDay = (date) => {
  const [y, m, d] = date.split('.').map((e) => +e);
  return (y - STANDARD_YEAR) * MONTH * 12 + MONTH * m + d;
};

function solution(today, terms, privacies) {
  var answer = [];
  const term = {};
  const todayDate = transformDateToDay(today);
  // 약관 저장
  terms.forEach((e) => {
    const [key, value] = e.split(SPACE);
    term[key] = +value * MONTH;
  });

  // 정보 변환 -> 약관 객체화
  const privateList = privacies.map((privacie) => {
    const [date, termType] = privacie.split(SPACE);
    return {
      date: transformDateToDay(date),
      termType,
    };
  });
  // 약관 유효성 계산
  // 수집일자 + 약관 유효기간 > 오늘 => 파기해야함
  privateList.forEach((private, index) => {
    if (private.date + term[private.termType] <= todayDate) {
      answer.push(index + 1);
    }
  });

  return answer;
}
const MONTH = 28;
const SPACE = ' ';
const STANDARD_YEAR = 2000;

// YYYY.MM.DD
const transformDateToDay = (date) => {
  const [y, m, d] = date.split('.').map((e) => +e);
  return (y - STANDARD_YEAR) * MONTH * 12 + MONTH * m + d;
};

function solution(today, terms, privacies) {
  var answer = [];
  const term = {};
  const todayDate = transformDateToDay(today);
  // 약관 저장
  terms.forEach((e) => {
    const [key, value] = e.split(SPACE);
    term[key] = +value * MONTH;
  });

  // 정보 변환 -> 약관 객체화
  const privateList = privacies.map((privacie) => {
    const [date, termType] = privacie.split(SPACE);
    return {
      date: transformDateToDay(date),
      termType,
    };
  });
  // 약관 유효성 계산
  // 수집일자 + 약관 유효기간 > 오늘 => 파기해야함
  privateList.forEach((private, index) => {
    if (private.date + term[private.termType] <= todayDate) {
      answer.push(index + 1);
    }
  });

  return answer;
}
