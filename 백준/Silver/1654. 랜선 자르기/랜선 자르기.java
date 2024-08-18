import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int K, N;
    static long[] len;
    static long maxLength = 1;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        K = input(st); // 1 ~ 10000
        N = input(st); // 1 ~ 1000000

        // 랜선 길이 입력받기
        len = new long[K];
        for (int i = 0; i < K; i++) {
            len[i] = input();
        }

        // 길이가 서로 다른 K개의 랜선 보유, 길이가 같은 N개의 랜선 필요 (K <= N)
        // 랜선이 N개 이상 만들어질 때, 랜선의 최대 길이는?
        // 이분 탐색 -> 최소 길이 1, 최대 길이 2^31-1
        binarySearch(0,Integer.MAX_VALUE);

        // 정답 출력
        System.out.println(maxLength);

    }

    static void binarySearch(long start, long end){
        if(start > end){
            return;
        }

        long cnt = 0;
        long mid = (start + end)/2;

        for (int i = 0; i < K; i++) {
            cnt += len[i]/mid;
        }

        // 랜선의 개수 >= N : 길이 늘리기 & 최대 길이 저장
        if(cnt >= N){
            if(mid >= maxLength){
                maxLength = mid;
                binarySearch(mid+1, end);
            }
            else{
                return;
            }
        }
        // 랜선의 개수 < N : 길이 줄이기
        else{
            binarySearch(start, mid-1);
        }

    }


    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}