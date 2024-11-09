import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static long n;
    static boolean[] isPrime;
    static List<Long> divisor = new ArrayList<>();

    public static void main(String[] args) throws IOException {
         n = Long.parseLong(br.readLine());
         getDivisor();
         long extraSet = countExtraSet(divisor.size(),1,1);
         System.out.println(n-extraSet);
    }

    // 소수인 약수 구하기
    static void getDivisor(){
        int sqrt = (int) Math.sqrt(n)+1;
        isPrime = new boolean[sqrt+1];
        Arrays.fill(isPrime,true);

        long res = n;

        for(int i=2; i<sqrt; i++){
            if (isPrime[i]) {
                for (int k = 2 * i; k <= sqrt; k += i) {
                    isPrime[k] = false;
                }
                if (res % i == 0) {
                    divisor.add((long) i);
                    while (res % i == 0) {
                        res /= i;
                    }
                }
            }
        }
        if(res !=1) divisor.add(res);
    }

    // 여집합
    static long countExtraSet(int idx, long val, int cnt){
        long set = 0;

        for(int i=0; i<idx; i++){
            long temp = val*divisor.get(i);
            if(temp>n) break;

            if(cnt%2 == 1){
                set += n/temp;
            }
            else{
                set -= n/temp;
            }
            set += countExtraSet(i, temp, cnt+1);
        }
        return set;
    }
}