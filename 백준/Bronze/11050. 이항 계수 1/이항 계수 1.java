import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = input(st);
        int K = input(st);


        System.out.println(factor(N) / (factor(N-K) * factor(K)));


    }

    static int factor(int n){
        if(n <= 1) return 1;

        return n * factor(n-1);
    }

    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}