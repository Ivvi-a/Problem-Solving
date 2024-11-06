public class Main {
    public static void main(String[] args) {
        int range = 1000000;
        boolean[] isPrime = new boolean[range];
        Arrays.fill(isPrime, true);

        isPrime[0] = isPrime[1] = false;

        for(int i=2; i<range; i++){
            if(!isPrime[i]){
                continue;
            }
            for(int k=2*i; k<range; k+=i){
                isPrime[k] = false;
            }
        }
    }
}
