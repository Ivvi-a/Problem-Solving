public class Main {
    static int node = 10000; // 노드 수
    static int edge = 1000; // 간선 수
    static boolean[][] connected = new boolean[node+1][node+1]; // 두 노드의 연결 여부
    static boolean[] visited = new boolean[node+1]; // 방문 여부

    public static void main(String[] args) {
        // 간선 정보(연결 여부) 저장
        for(int i=0; i<edge; i++){
            // int a = input
            // int b = input
            // connected[a][b] = true
            // connected[b][a] = true
        }

        int startNode = 1; // 탐색 시작 노드
        DFS(startNode);
    }

    static void DFS(int n){
        visited[n] = true;
        for(int i=1; i<=node; i++){
            if(connected[n][i] && !visited[i]){
                DFS(i);
            }
        }
    }
}
