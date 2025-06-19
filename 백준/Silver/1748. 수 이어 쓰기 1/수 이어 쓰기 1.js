const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

let len = input.length;
let N = parseInt(input);
let answer = 0;

while (len > 0) {
  let len2 = len - 1;
  let minNum = 0;
  let times = 1;
  while (len2 > 0) {
    minNum += 9 * times;
    times *= 10;
    len2--;
  }
  const tempNum = N - parseInt(minNum);
  answer += tempNum * len;
  N -= tempNum;
  len--;
}

console.log(answer);
