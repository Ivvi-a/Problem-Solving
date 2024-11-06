import java.util.*;
import java.io.*;

public class Main{
    static boolean[] visited;
    static int[][] arr;
    static int N,M;
    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine()); // 컴퓨터 수
        M = Integer.parseInt(br.readLine()); // 간선 수

        // 간선 정보
        arr = new int[N+1][N+1]; // 연결 여부
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            arr[a][b] = 1;
            arr[b][a] = 1;
        }

        // 탐색
        visited = new boolean[N+1];
        dfs(1);
        System.out.println(cnt);

    }

    public static void dfs(int v){
        visited[v] = true;
        for(int i=1; i<=N; i++){
            if(arr[v][i]==1 && !visited[i]){
                cnt++;
                dfs(i);
            }
        }
    }
}