import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N;
    static ArrayList<Integer> arr = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        N = input();

        int sum = 0;
        for (int i = 0; i < N; i++) {
            int n = input();
            sum += n;
            arr.add(n);
        }

        Collections.sort(arr);

        ArrayList<Integer> maxCntValue = new ArrayList<>();
        int cnt = 1;
        int maxCnt = 1;

        for (int i = 0; i < N - 1; i++) {
            if (arr.get(i).equals(arr.get(i + 1))) {
                cnt++;
            } else {
                if (cnt > maxCnt) {
                    maxCnt = cnt;
                    maxCntValue.clear();
                    maxCntValue.add(arr.get(i));
                } else if (cnt == maxCnt) {
                    maxCntValue.add(arr.get(i));
                }
                cnt = 1;
            }
        }

        // 마지막 요소 처리
        if (cnt > maxCnt) {
            maxCntValue.clear();
            maxCntValue.add(arr.get(N - 1));
        } else if (cnt == maxCnt) {
            maxCntValue.add(arr.get(N - 1));
        }

        // 산술 평균
        System.out.println(Math.round((float) sum/N));
        // 중앙값
        System.out.println(arr.get(N/2));
        // 최빈값
        if(maxCntValue.size() == 1){
            System.out.println(maxCntValue.get(0));
        }
        else{
            System.out.println(maxCntValue.get(1));
        }
        // 범위
        System.out.println(arr.get(N-1)-arr.get(0));

    }


    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}