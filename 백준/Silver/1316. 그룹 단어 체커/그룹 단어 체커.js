const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = parseInt(input[0]); // 문자열 개수
const arr = input.slice(1).map((elm) => elm.trim()); // 문자열 배열
let answer = 0;

for (i = 0; i < arr.length; i++) {
  let visited = Array(100).fill(false);
  let isGroupWord = true;
  for (j = 0; j < arr[i].length; j++) {
    const a = arr[i][j];
    if (visited[a] && a != arr[i][j - 1]) {
      isGroupWord = false;
      break;
    } else visited[a] = true;
  }
  if (isGroupWord) answer++;
}

console.log(answer);
