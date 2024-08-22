import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static long M, ans;
    static int[] primeNumber;

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        N = input(st);
        M = Long.parseLong(st.nextToken());

        primeNumber = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            primeNumber[i] = input(st);
        }

        // 포함-배제의 원리
        ans = 0;

        // N = 3인 경우,
        // 1 ~ 7 반복 : N개의 요소로 만들 수 있는 모든 부분집합을 순회 (공집합 제외)
        // (1 << N) = 2^N
        for (int bit = 1; bit < (1 << N); bit++) {
            int cnt = 0; // 부분집합에 포함된 요소의 개수
            long val = 1; // 부분집합에 포함된 요소들의 곱

            // 0 ~ 2 반복 : 부분집합의 각 요소를 확인
            for (int i = 0; i < N; i++) {
                // bit에서 i번째 비트가 1인지 확인
                if((bit & (1 << i)) != 0){
                    cnt++;
                    val *= primeNumber[i];
                }
            }

//            System.out.println("bit = "+bit+", cnt = "+cnt+", val = "+val);

            // 홀수인 경우 : 더하기
            if(cnt%2 == 1){
                ans += M/val; // 1~M까지 자연수 중, val로 나누어떨어지는 자연수의 개수 = val의 배수 = M/val
            }
            // 홀수인 경우 : 빼기
            else{
                ans -= M/val;
            }
        }

        System.out.println(ans);

    }

    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }

}