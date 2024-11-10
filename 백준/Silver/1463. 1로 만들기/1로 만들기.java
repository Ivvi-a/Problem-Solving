import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int X = Integer.parseInt(br.readLine());
        int[] dp = new int[X+3];
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;

        for(int i=4; i<=X; i++){
            if(i%3 == 0 && i%2 == 0){
                dp[i] = Math.min(dp[i/3]+1, Math.min(dp[i/2]+1, dp[i-1]+1));
            }
            else if(i%3 == 0){
                dp[i] = Math.min(dp[i/3]+1, dp[i-1]+1);
            }
            else if(i%2 == 0){
                dp[i] = Math.min(dp[i/2]+1, dp[i-1]+1);
            }
            else{
                dp[i] = Math.min(dp[i-1]+1, dp[i-2]+2);
            }
        }
        System.out.println(dp[X]);
    }
}