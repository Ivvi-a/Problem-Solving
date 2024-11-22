import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Node{
	int v, cost;
	public Node(int v, int cost) {
		this.v = v;
		this.cost = cost;
	}
}

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M,X,ans;
	static ArrayList<ArrayList<Node>> graph = new ArrayList<>();
	static int INF = 1234567890;
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = input(st); // 학생 수 (정점)
		M = input(st); // 도로 수 (간선)
		X = input(st); // 도착점

		for(int i=0; i<N+1; i++) {
			graph.add(new ArrayList<Node>());
		}
		
		// 단방향 간선 입력받기
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int start = input(st);
			int end = input(st);
			int cost = input(st);
			
			graph.get(start).add(new Node(end,cost));
		}
		
		// 모든 점에서 다익스트라 알고리즘
		for(int i=1; i<=N; i++) {
			ans = Math.max(ans, dijstra(i,X) + dijstra(X,i));
		}
		
		System.out.println(ans);
		
	}
	
	static int dijstra(int start, int end) {
		// 방문 배열
		boolean[] visited = new boolean[N+1];
		
		// 거리 배열
		int[] dist = new int[N+1];
		Arrays.fill(dist, INF);
		dist[start] = 0;
		
		// 우선순위 큐
		PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
		pq.offer(new Node(start,0));
		
		while(!pq.isEmpty()) {
			Node curNode = pq.poll();
			
			if(visited[curNode.v]) continue;
			visited[curNode.v] = true;
			
			for(int i=0; i<graph.get(curNode.v).size(); i++) {
				Node nextNode = graph.get(curNode.v).get(i);
				
				if(dist[nextNode.v] > dist[curNode.v] + nextNode.cost) {
					dist[nextNode.v] = dist[curNode.v] + nextNode.cost;
					pq.offer(new Node(nextNode.v, dist[nextNode.v]));
				}
			}
		}
        
		return dist[end];
	}
	
	// ---------------
	static int input() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	static int input(StringTokenizer st) {
		return Integer.parseInt(st.nextToken());
	}
}