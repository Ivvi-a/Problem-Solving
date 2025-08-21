function solution(cacheSize, cities) {
  var answer = 0;
  let cache = [];
    
  cities.forEach((it) => {
    // 대소문자 구분 x
    const city = it.toLowerCase();
    if(cacheSize === 0){
        answer += 5;
    }
    // cache hit 1
    else if (cache.includes(city)) {
      cache = cache.filter((it) => it !== city);
      cache.push(city);
      answer += 1;
    }
    // cache miss 5
    else {
      if (cache.length >= cacheSize) cache.shift();
      cache.push(city);
      answer += 5;
    }
  });

  return answer;
}
