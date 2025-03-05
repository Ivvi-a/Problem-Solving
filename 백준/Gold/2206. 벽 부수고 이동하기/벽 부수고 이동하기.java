import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node{
    int r,c,dist;
    boolean wall;
    public Node(int r, int c, int dist, boolean wall){
        this.r = r;
        this.c = c;
        this.dist = dist;
        this.wall = wall;
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N,M,ans;
    static int[][] map;
    static boolean[][][] visited;
    static int[] dr = {1,-1,0,0};
    static int[] dc = {0,0,1,-1};

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = input(st);
        M = input(st);
        map = new int[N][M];

        // 맵 입력받기
        for(int i=0; i<N; i++){
            String str = br.readLine();
            for(int k=0; k<M; k++){
                map[i][k] = str.charAt(k)-'0';
            }
        }

        BFS();

        if(ans==0){
            System.out.println(-1);
        }
        else{
            System.out.println(ans);
        }
    }

    static void BFS(){
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0,0,1,false));

        visited = new boolean[N][M][2];
        visited[0][0][0] = true;

        while(!q.isEmpty()){
            Node node = q.poll();

            if(node.r == N-1 && node.c == M-1){
                ans = node.dist;
                return;
            }

            for(int d=0; d<4; d++){
                int nr = node.r + dr[d];
                int nc = node.c + dc[d];

                if(!index(nr,nc)) continue;

                // 벽이 아닐 때
                if(map[nr][nc]==0){
                    // 방문 안한 경우
                    if(!visited[nr][nc][0] && !node.wall){
                        visited[nr][nc][0] = true;
                        q.offer(new Node(nr,nc,node.dist+1, false));
                    }
                    else if(!visited[nr][nc][1] && node.wall){
                        visited[nr][nc][1] = true;
                        q.offer(new Node(nr,nc,node.dist+1, true));
                    }
                }
                // 벽을 만났을 때
                else{
                    // 방문 안했고, 아직 벽을 안 부순 경우
                    if(!visited[nr][nc][1] && !node.wall){
                        visited[nr][nc][1] = true;
                        q.offer(new Node(nr,nc,node.dist+1,true));
                    }
                }
            }
        }

    }

    // ----------------------------
    static boolean index(int r, int c){
        return r>=0 && c>=0 && r<N && c<M;
    }
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}