import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static boolean[] isPrime = new boolean[10000000];
    static ArrayList<Integer> primeNumbers = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        getPrimeNumbers();
        N = Integer.parseInt(br.readLine());
        primeFactorization(0);
    }

    static void primeFactorization(int idx){
        if(N == 1 || idx == primeNumbers.size()){
            return;
        }
        int pn = primeNumbers.get(idx);
        while(N%pn==0){
            N /= pn;
            System.out.println(pn);
        }
        primeFactorization(++idx);
    }

    static void getPrimeNumbers(){
        Arrays.fill(isPrime,true);
        for (int i = 2; i < isPrime.length; i++) {
            if(isPrime[i]){
                for (int j = 2 * i; j < isPrime.length; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i < isPrime.length; i++) {
            if(isPrime[i]){
                primeNumbers.add(i);
            }
        }
    }

}