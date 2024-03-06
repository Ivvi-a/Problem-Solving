import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static long[] dp = new long[101];

    public static void main(String[] args) throws IOException {
        int T = input();

        // dp[1,2,3] = 1
        // dp[4,5] = 2
        // dp[n] = dp[n-1] + dp[n-5]

        for(int i=1; i<=3; i++){
            dp[i] = 1;
        }

        for(int i=4; i<=5; i++){
            dp[i] = 2;
        }

        StringBuilder sb = new StringBuilder();

        while(T-->0){
            int n = input();
            sb.append(dp(n)).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();

    }

    static long dp(int n) {
        if(dp[n] == 0){
            return dp[n] = dp(n-1) + dp(n-5);
        }

        return dp[n];

    }

    static int input() throws  IOException{
        return Integer.parseInt(br.readLine());
    }

}