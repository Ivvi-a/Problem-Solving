import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N,M;
    static int minCount = 64;
    static char[][] board;
    static char[] color = {'B','W'};

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = input(st);
        M = input(st);
        board = new char[N][M];

        // 보드판 입력받기
        for (int i = 0; i <N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = str.charAt(j);
            }
        }

        // 시작점 index 0 ~ N/M-7까지 체크
        for (int i = 0; i < N - 7; i++) {
            for (int j = 0; j < M - 7; j++) {
                int temp = calc(i, j);
                minCount = Math.min(minCount, temp);
            }
        }
        System.out.println(minCount);
    }

    static int calc(int n, int m){
        int blackCount = startAtBlack(n, m);
        int whiteCount = startAtWhite(n, m);

        return Math.min(blackCount, whiteCount);
    }

    // B로 시작하는 경우
    static int startAtBlack(int n, int m){
        int idx = 0;
        int cnt = 0;
        for (int i = n; i < n + 8; i++) {
            for (int j = m; j < m + 8; j++) {
                if(board[i][j] != color[idx]){
                    cnt++;
                    if(cnt >= minCount){
                        return cnt;
                    }
                }
                if(j != m+7){
                    idx = (idx+1) % 2;
                }
            }
        }
        return cnt;
    }

    // W로 시작하는 경우
    static int startAtWhite(int n, int m){
        int idx = 1;
        int cnt = 0;
        for (int i = n; i < n + 8; i++) {
            for (int j = m; j < m + 8; j++) {
                if(board[i][j] != color[idx]){
                    cnt++;
                    if(cnt >= minCount){
                        return cnt;
                    }
                }
                if(j != m+7){
                    idx = (idx+1) % 2;
                }
            }
        }
        return cnt;
    }

    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}