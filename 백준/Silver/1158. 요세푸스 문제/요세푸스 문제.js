const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split(" ");

const N = input[0];
const K = parseInt(input[1]);

let list = Array.from({ length: N }, (_, i) => i + 1);
let idx = 0;

let answer = "<";

while (list.length > 0) {
  idx = (idx + K - 1) % list.length;
  answer += list[idx];
  if (list.length != 1) answer += ", ";
  list.splice(idx, 1);
}
answer += ">";
console.log(answer);