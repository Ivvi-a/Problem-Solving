import java.util.*;

class Solution {
    static int[] sum;
    static boolean[][] visited;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    
    public int solution(int[][] land) {
        int answer = 0;
        int y = land.length;
        int x = land[0].length;
        
        sum = new int[x];
        visited = new boolean[y][x];
        
        for(int i=0; i<y; i++){
            for(int k=0; k<x; k++){
                if(!visited[i][k] && land[i][k] == 1){
                    BFS(land, new Node(i,k), y, x);
                }
            }
        }
        
        for(int s : sum){
            answer = Math.max(answer, s);
        }
        
        return answer;
    }
    
    static void BFS(int[][] land, Node n, int y, int x){
        boolean[] loc = new boolean[x];
        Queue<Node> q = new LinkedList<>();
        int cnt = 0;
        q.offer(n);
        
        while(!q.isEmpty()){
            Node now = q.poll();
            
            if(!loc[now.x]){
                loc[now.x] = true;
            }
            if(!visited[now.y][now.x]){
                visited[now.y][now.x] = true;
                cnt++;
                
                for(int d=0; d<4; d++){
                    int ny = now.y + dy[d];
                    int nx = now.x + dx[d];
                    if(ny >= y || nx >= x || ny < 0 || nx < 0) continue;
                    if(land[ny][nx] == 1){
                        q.offer(new Node(ny, nx));
                    }
                }
            }
        }
        
        for(int i=0; i<x; i++){
            
            if(loc[i]) sum[i] += cnt;
        }
    }
}

class Node{
    int x, y;
    public Node(int y, int x){
        this.x = x;
        this.y = y;
    }
}