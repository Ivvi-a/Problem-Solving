import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

class Edge{
	int s,e,cost;
	public Edge(int s, int e, int cost) {
		this.s = s;
		this.e = e;
		this.cost = cost;
	}
}

public class Main {
	// 변수
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int N,M;
	static long[] dist;
	static ArrayList<Edge> graph;
	static int INF = 1234567890;
	
	// main
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = input(st); // 도시 수 (정점)
		M = input(st); // 버스 수 (간선)
		
		// 거리 배열 초기화
		dist = new long[N+1];
		Arrays.fill(dist, INF);
		dist[1] = 0;
		
		// 간선 정보 입력
		graph = new ArrayList<>();
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			int A = input(st); // 시작
			int B = input(st); // 도착
			int C = input(st); // 비용
			
			graph.add(new Edge(A,B,C));
		}
		
		if(!bellmanFord()) {
			System.out.println(-1);
		}
		else {
			print();
		}
		
	}
	
	// 벨만 포드 알고리즘
	static boolean bellmanFord() {
		// 정점 개수만큼 반복
		for(int i=0; i<N-1; i++) {
			// 간선 개수만큼 반복
			for(int k=0; k<M; k++) {
				Edge edge = graph.get(k); // 현재 간선
				
				if(dist[edge.s]!=INF) {
					if(dist[edge.e] > dist[edge.s] + edge.cost) {
						dist[edge.e] = dist[edge.s] + edge.cost;
					}
				}
			}
		}
		
		// 음수 가중치 확인
		for(int i=0; i<M; i++) {
			Edge edge = graph.get(i);
			
			if(dist[edge.s]!=INF) {
				if(dist[edge.e] > dist[edge.s] + edge.cost) {
					return false;
				}
			}
		}
		return true;
		
	}
	
	static void print() {
		StringBuilder sb = new StringBuilder();
		
		for(int i=2; i<=N; i++) {
			if(dist[i]==INF) {
				sb.append(-1).append("\n");
			}
			else {
				sb.append(dist[i]).append("\n");
			}
		}
		
		System.out.println(sb);
		
	}
	
	// ---------------
	static int input() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	static int input(StringTokenizer st) {
		return Integer.parseInt(st.nextToken());
	}
}