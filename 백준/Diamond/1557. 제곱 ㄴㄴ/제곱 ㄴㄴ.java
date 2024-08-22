import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final long LIMIT = Integer.MAX_VALUE;
    static long K, ans;
    static boolean[] isPrime;
    static ArrayList<Integer> poweredPrime = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        K = Integer.parseInt(br.readLine());
        getPrimeList();
        binarySearch(K,LIMIT);
        System.out.println(ans);
    }

    // 이분 탐색
    static void binarySearch(long start, long end){
        if(start > end){
            return;
        }
        long mid = start + (end - start) / 2;
        long cnt = mid - countExtraSet(mid, poweredPrime.size(), 1, 1);

        if(cnt >= K){
            ans = mid;
            binarySearch(start, mid-1);
        }
        else {
            binarySearch(mid+1, end);
        }

    }

    // 1부터 N까지 제곱의 배수 구하기
    static int countExtraSet(long N, int idx, long val, int cnt) {
        int extraSet = 0;

        for (int i = 0; i < idx; i++) {
            long temp = val * poweredPrime.get(i);
            if (temp > N) break;


            if (cnt % 2 == 1) {
                extraSet += (int) (N/temp);
            } else {
                extraSet -= (int) (N/temp);
            }

            extraSet += countExtraSet(N, i, temp, cnt+1);

        }

        return extraSet;
    }


    // 에라토스테네스의 채 -> 루트 2K까지 소수 구하기
    static void getPrimeList(){
        int range = (int) Math.ceil(Math.sqrt(LIMIT));

        isPrime = new boolean[range+1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i <= range; i++) {
            if(isPrime[i]){
                for (int j = 2*i; j <= range; j+=i) {
                    if(isPrime[j]) isPrime[j] = false;
                }

                // 제곱, 제곱의 배수 리스트에 넣기
                poweredPrime.add(i*i);

            }
        }
    }
}