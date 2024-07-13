import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, groupCnt, maxLineCnt = 0;
    static int[] parent = new int[3001];
    static int[][] line = new int[3001][4];

    public static void main(String[] args) throws IOException {
        N = input(); // 선분의 수

        for(int i=1; i<=N; i++){
            parent[i] = -1;
        }

        for(int i=1; i<=N; i++){
            st = new StringTokenizer(br.readLine());
            for(int k=0; k<4; k++){
                line[i][k] = input(st);
            }

            // 선분이 교차하는 경우 union
            for(int k=1; k<i; k++){
                if(isCross(line[i][0], line[i][1], line[i][2], line[i][3], line[k][0], line[k][1], line[k][2], line[k][3])){
                    union(i,k);
                }
            }

        }

        // 그룹 수, 선의 최대 개수 구하기
        for(int i=1; i<=N; i++){
            // 음수 -> 그룹 수 cnt
            if(parent[i] < 0){
                groupCnt++;
                maxLineCnt = Math.min(maxLineCnt, parent[i]);
            }
        }

        // 정답 출력
        System.out.println(groupCnt);
        System.out.println(-maxLineCnt);

    }

    // 유니온 파인드
    static int find(int n){
        if(parent[n] < 0){
            return n;
        }
        return parent[n] = find(parent[n]);
    }

    static void union(int a, int b){
        int x = find(a);
        int y = find(b);

        if(x==y){
            return;
        }

        parent[x] += parent[y];
        parent[y] = x;

    }

    // ccw 알고리즘
    static int CCW(long x1, long y1, long x2, long y2, long x3, long y3){
        long res = (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);

        if(res > 0) return 1; // 반시계 방향
        else if (res < 0) return -1; // 시계 방향
        return 0; // 일직선
    }

    static boolean isOverlab(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4){
        if(Math.max(x1,x2) >= Math.min(x3,x4) && Math.max(x3,x4) >= Math.min(x1,x2) && Math.max(y1,y2) >= Math.min(y3,y4) && Math.max(y3,y4) >= Math.min(y1,y2)){
            return true;
        }
        return false;
    }

    static boolean isCross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4){
        int abc = CCW(x1, y1, x2, y2, x3, y3);
        int abd = CCW(x1, y1, x2, y2, x4, y4);
        int cda = CCW(x3, y3, x4, y4, x1, y1);
        int cdb = CCW(x3, y3, x4, y4, x2, y2);

        if(abc*abd == 0 && cda*cdb == 0){
            return isOverlab(x1, y1, x2, y2, x3, y3, x4, y4);
        }
        else if(abc*abd <=0 && cda*cdb <=0){
            return true;
        }
        return false;
    }

    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}