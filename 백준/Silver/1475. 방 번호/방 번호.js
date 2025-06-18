const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = input[0];
const count = Array(9).fill(0);

for (i = 0; i < N.length; i++) {
  const n = N[i];
  if (n == 9) count[6]++;
  else count[n]++;
}

let answer = 0;

for (i = 0; i < count.length; i++) {
  if (i == 6) answer = Math.ceil(Math.max(answer, count[i] / 2));
  else answer = Math.max(answer, count[i]);
}

console.log(answer);