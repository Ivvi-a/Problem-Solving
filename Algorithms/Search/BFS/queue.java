import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

public class Main {
    static int node = 10000; // 노드 수
    static int edge = 1000; // 간선 수
    static ArrayList<Integer>[] graph = new ArrayList[node+1]; // 두 노드의 연결 여부
    static boolean[] visited = new boolean[node+1]; // 방문 여부

    public static void main(String[] args) {
        // ArrayList 초기화
        for(int i=0; i<node+1; i++){
            graph[i] = new ArrayList<Integer>();
        }

        // 간선 정보(연결 여부) 저장
        for(int i=0; i<edge; i++){
            // int a = input
            // int b = input
            // graph[a].add(b)
            // graph[b].add(a)
        }

        int startNode = 1;
        BFS(startNode);
    }

    static void BFS(int startNode){
        Queue<Integer> queue = new LinkedList<>(); // 큐
        queue.offer(startNode);
        visited[startNode] = true;

        while(!queue.isEmpty()){
            int nowNode = queue.poll();

            for(int connectedNode : graph[nowNode]){
                if(!visited[connectedNode]){
                    visited[connectedNode] = true;
                    queue.offer(connectedNode);
                }
            }
        }
    }
}
