let fs = require("fs");
let input = fs.readFileSync("./input.txt").toString().split("\n");

const BNP = (totalPrice, dayPrice) => {
  let priceNum = 0;
  for (let i = 0; i < 14; i++) {
    if (totalPrice / dayPrice[i]) {
      priceNum += parseInt(totalPrice / dayPrice[i]);
      totalPrice %= dayPrice[i];
    }
  }
  return priceNum * dayPrice[13] + totalPrice;
};

const TIMING = (totalPrice, dayPrice) => {
  let isIncrease = 0;
  let isDecrease = 0;
  let priceNum = 0;

  for (let i = 1; i < 14; i++) {
    if (dayPrice[i] > dayPrice[i - 1]) {
      isIncrease++;
      isDecrease = 0;
    }
    if (dayPrice[i] < dayPrice[i - 1]) {
      isDecrease++;
      isIncrease = 0;
    }
    if (dayPrice[i] === dayPrice[i - 1]) {
        isDecrease = 0;
        isIncrease = 0;
        continue;
    }
    if (isIncrease === 3) {
      totalPrice += dayPrice[i] * priceNum;
      priceNum = 0;
      isIncrease = 0;
    }
    if (isDecrease === 3) {
      priceNum += parseInt(totalPrice / dayPrice[i]);
      totalPrice %= dayPrice[i];
      isDecrease = 0;
    }
  }
  return priceNum * dayPrice[13] + totalPrice;
};

const solution = (input) => {
  let totalPrice = parseInt(input[0]);
  let dayPrice = input[1].split(" ").map((el) => +el);

  console.log(TIMING(totalPrice, dayPrice));
  if (BNP(totalPrice, dayPrice) > TIMING(totalPrice, dayPrice)) {
    return "BNP";
  }
  if (BNP(totalPrice, dayPrice) < TIMING(totalPrice, dayPrice)) {
    return "TIMING";
  }
  return "SAMESAME";
};

console.log(solution(input));