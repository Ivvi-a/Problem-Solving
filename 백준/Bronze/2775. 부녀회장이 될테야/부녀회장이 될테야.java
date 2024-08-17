import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] arr = new int[15][15];

    public static void main(String[] args) throws IOException {
        int T = input();

        for (int i = 0; i < 15; i++) {
            arr[0][i] = i;
        }

        while(T-->0){
            int k = input();
            int n = input();
            System.out.println(calc(k,n));
        }
    }

    static int calc(int k, int n){
        if(arr[k][n] != 0){
            return arr[k][n];
        }

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += calc(k-1, i);
        }
        return sum;
    }


    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}