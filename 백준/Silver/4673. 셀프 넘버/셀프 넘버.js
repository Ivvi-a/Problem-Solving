let visited = Array(10001).fill(false);

for (i = 1; i <= 10000; i++) {
  let n = i;
  let str = String(n);
  for (j = 0; j < str.length; j++) {
    n += Number(str[j]);
  }
  if (n <= 10000) visited[n] = true;
}

for (i = 1; i <= 10000; i++) {
  if (!visited[i]) console.log(i);
}
