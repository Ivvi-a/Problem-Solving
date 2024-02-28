import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] dp = new int[12];

    public static void main(String[] args) throws IOException {
        int T = input();

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        StringBuilder sb = new StringBuilder();

        while(T-->0){
            int n = input();
            sb.append(dp(n)).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();

    }

    static int dp(int n) {
        if(dp[n] == 0){
            return dp[n] = dp(n-1) + dp(n-2) + dp(n-3);
        }

        return dp[n];

    }

    static int input() throws  IOException{
        return Integer.parseInt(br.readLine());
    }

}