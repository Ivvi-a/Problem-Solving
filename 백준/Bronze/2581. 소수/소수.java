import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int M,N;
    static boolean[] isPrime;
    static int sum, firstPrime = 0;

    public static void main(String[] args) throws IOException {
        M = Integer.parseInt(br.readLine());
        N = Integer.parseInt(br.readLine());
        getPrimeNumbers();
        getSum();

        if(sum == 0){
            System.out.println(-1);
        }
        else{
            System.out.println(sum);
            System.out.println(firstPrime);
        }
    }

    static void getSum(){
        boolean isFirst = true;
        for (int i = M; i <= N; i++) {
            if(isPrime[i]){
                if(isFirst){
                    isFirst = false;
                    firstPrime = i;
                }
                sum += i;
            }
        }
    }

    static void getPrimeNumbers(){
        isPrime = new boolean[N+1];
        Arrays.fill(isPrime,true);
        isPrime[1] = false;

        for (int i = 2; i < isPrime.length; i++) {
            if(isPrime[i]){
                for (int j = 2 * i; j < isPrime.length; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
    }

}