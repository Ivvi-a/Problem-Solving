import java.util.*;

public class Main {
    static int node, edge; // 정점, 간선 개수
    static int[] indegree = new int[100001]; // 진입 차수
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>(); // 그래프 - 간선 정보
    static ArrayList<Integer> result = new ArrayList<>(); // 위상 정렬 수행 결과

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        node = sc.nextInt();
        edge = sc.nextInt();

        // 그래프 초기화
        for (int i = 0; i <= node; i++) {
            graph.add(new ArrayList<Integer>());
        }

        // 간선 정보 입력 받기
        for (int i = 0; i < edge; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph.get(a).add(b); // 정점 A에서 B로 이동 가능
            indegree[b] += 1; // 진입차수+1
        }

        topology_sort();

        // 결과 출력
        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i) + " ");
        }
    }

    // 위상 정렬
    static void topology_sort() {
        Queue<Integer> q = new LinkedList<>(); // 큐

        // 진입차수가 0인 노드를 큐에 넣기
        for (int i = 1; i <= node; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        // 정점 개수만큼 반복
        for(int i = 0; i< node; i++){
            // v번 실행을 마치기 전 큐가 비었다면 -> 사이클 존재
            if(q.isEmpty()){
                System.out.println("사이클 발생");
                return;
            }

            // 큐에서 원소 꺼내기
            int nowNode = q.poll();
            result.add(nowNode);

            // 해당 원소와 연결된 노드들의 진입차수-1
            for (int k = 0; k < graph.get(nowNode).size(); k++) {
                indegree[graph.get(nowNode).get(k)]--;
                // 새롭게 진입차수가 0이 되는 노드를 큐에 넣기
                if (indegree[graph.get(nowNode).get(k)] == 0) {
                    q.offer(graph.get(nowNode).get(k));
                }
            }
        }
    }
}
