function solution(n) {
  const types = [500, 100, 50, 10];
  let count = 0;
  types.forEach((coin) => {
    count += Math.floor(n / coin);
    n = n % coin;
  });
  return count;
}

console.log(solution(1260));
