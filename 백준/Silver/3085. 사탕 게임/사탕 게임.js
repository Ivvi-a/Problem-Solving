const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// 변수
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];
let answer = 1;

// 함수
function swap(arr, y1, x1, y2, x2) {
  const temp = arr[y1][x1];
  arr[y1][x1] = arr[y2][x2];
  arr[y2][x2] = temp;
}

function row(arr) {
  let maxLen = 1;
  for (let y = 0; y < N; y++) {
    let cnt = 1;
    for (let x = 1; x < N; x++) {
      if (arr[y][x] == arr[y][x - 1]) {
        cnt++;
        if (x == N - 1) maxLen = Math.max(cnt, maxLen);
      } else {
        maxLen = Math.max(cnt, maxLen);
        cnt = 1;
      }
    }
  }
  return maxLen;
}

function col(arr) {
  let maxLen = 1;
  for (let x = 0; x < N; x++) {
    let cnt = 1;
    for (let y = 1; y < N; y++) {
      if (arr[y][x] == arr[y - 1][x]) {
        cnt++;
        if (y == N - 1) maxLen = Math.max(cnt, maxLen);
      } else {
        maxLen = Math.max(cnt, maxLen);
        cnt = 1;
      }
    }
  }
  return maxLen;
}

// 입력받기
const N = parseInt(input[0]);
let arr = Array.from({ length: N }, () => Array(N).fill(0));

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    arr[i][j] = input[i + 1][j];
  }
}

// 계산
for (let y = 0; y < N; y++) {
  for (let x = 0; x < N; x++) {
    for (let d = 0; d < 4; d++) {
      const nx = x + dx[d];
      const ny = y + dy[d];
      if (nx < 0 || ny < 0 || nx >= N || ny >= N || arr[ny][nx] == arr[y][x]) {
        continue;
      }
      swap(arr, y, x, ny, nx);
      answer = Math.max(answer, Math.max(row(arr), col(arr)));
      swap(arr, y, x, ny, nx);
    }
  }
}

console.log(answer);