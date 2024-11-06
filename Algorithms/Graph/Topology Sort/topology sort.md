# 위상 정렬

- ****位相 (자리 위, 서로 상) :**** 어떤 사물이 다른 사물과의 관계 속에서 가지는 위치나 양상
- **순서가 정해져 있는 작업**을 차례로 수행해야 할 때, 작업 순서를 정렬
- 시간복잡도: **O(V+E)**
    
    ![111](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/5b684ba3-8988-49f9-b6ce-457670fe439c)

## 어떤 문제에 쓰지?
1. Directed Acyclic Graph(**DAG, 방향 비순환 그래프**)에만 적용 가능
- **사이클이 없는** 그래프
- **시작점** 존재 
 
    불가능한 경우 (사이클 있음, 시작점 없음)
    ![222](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/7a904391-e33b-4f2c-84a9-b676c74b974f)


2. 뭔가 **먼저** 하고, 뭔가 **나중에** 해야 할 때 (시간, 공간, 우선 순위, 비교...)
![순서2](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/9447c612-5dab-4cf5-99b5-18477162c55c)
![시작출발](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/122a8fca-bdcf-41d4-ab33-dc5c037842ce)
![위계](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/005d4fdf-335b-4f76-aa92-aa868b898918)
    

## 위상 정렬로 알 수 있는 것
1. 정렬이 가능한지 여부 (사이클 존재 여부)
2. 정렬 결과


## 필요한 변수
- **큐**
  <br>
    ```java
    Queue<Integer> q = new LinkedList<>();
    ```
- **간선 정보** 그래프
  <br>
    ```java
    List<List<Integer>> graph = new ArrayList<ArrayList<Integer>>();
    ```
- **진입 차수** (정점으로 들어오는 간선의 개수)
  <br>
    ```java
    int[] indegree = new int[노드 개수];
    ```
- 정렬 결과
  <br>
  ```java
  ArrayList<Integer> result = new ArrayList<>();
  ```
            

# 위상 정렬 과정
### 1.  그래프 간선 정보, 진입 차수 입력 받기
   ![t1](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/028e2953-9f61-4785-bbca-1114eb28ad21)
```java
   // 그래프 초기화
    for (int i = 0; i <= v; i++) {
        graph.add(new ArrayList<Integer>());
    }

    // 간선 정보 입력 받기
    for (int i = 0; i < e; i++) {
        int a = sc.nextInt();
        int b = sc.nextInt();
        graph.get(a).add(b); // 정점 A에서 B로 이동 가능
        indegree[b] += 1; // 진입차수+1
    }
```
        
### 2.  진입 차수가 0인 정점 → 큐에 넣기
   ![t2](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/517c064f-1c30-4e23-b824-837e4d441a10)
```java
    // 진입차수가 0인 노드를 큐에 넣기
    for (int i = 1; i <= v; i++) {
        if (indegree[i] == 0) {
            q.offer(i);
        }
    }
```

### 3.  큐에서 노드 하나 꺼내기 → 방문 노드로 설정
![t3](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/6c2001ea-5f58-4d33-be09-14d9a7dce5e3)
```java
  int now = q.poll();
  result.add(now); // 정렬 결과 리스트에 저장
```
        
### 4.  방문 노드와 인접한 노드 사이의 간선 제거 → 인접 노드의 진입차수 -1
![t4](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/da30f861-59f9-45e6-a330-4e3d7e97e55a)
```java
  // 방문 노드와 인접한 노드들의 진입차수-1
  for (int i = 0; i < graph.get(now).size(); i++) {
      indegree[graph.get(now).get(i)] -= 1;
      ...
  }
```

        
### 5.  인접 노드의 진입차수가 0이라면? → 큐에 넣기
![t5](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/b064185f-ad51-43ef-ae11-3f471f883144)
```java
    ...
    // 새롭게 진입차수가 0이 되는 노드를 큐에 넣기
      if (indegree[graph.get(now).get(i)] == 0) {
          q.offer(graph.get(now).get(i));
      }
```
    
### 6.  정점 개수만큼 3~5반복
#### - 모든 정점을 방문하기 전에 큐가 빈다면? 사이클 존재
```java
for(int i=0; i<v; i++){
  // v번 실행을 마치기 전 큐가 비었다면 -> 사이클 존재
  if(q.isEmpty){
    system.out.println("사이클 발생");
  }
  ...
}
```
#### - 모든 정점을 방문했다면? 큐에서 꺼낸 순서가 위상정렬 결과
  ![t6](https://github.com/soberdam/ssafy-10th-algorithm-study/assets/53993041/6249c24b-4a0e-4b1c-bf79-855ea40dda8c)
```java
// 결과 출력
for (int i = 0; i < result.size(); i++) {
    System.out.print(result.get(i) + " ");
}
```
