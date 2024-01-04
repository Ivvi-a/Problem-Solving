import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] arr;
    static int[] dp;
    static int N;

    // main
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        // 수열 입력받기
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[N];
        for(int i=0; i<N; i++) {
        	arr[i] = Integer.parseInt(st.nextToken());
        }
        
        dp = new int[N];
        
        dp[N-1] = 1;
        for(int i=N-2; i>=0; i--) {
        	for(int k=N-1; k>i; k--) {
        		if(dp[i]<dp[k] && arr[i]<arr[k]) {
        			dp[i] = dp[k];
        		}
        	}
        	dp[i] += 1;
        }
        
        int ans = 0;
        for(int i=0; i<N; i++) {
        	ans = Math.max(ans, dp[i]);
        }

        System.out.println(ans);

    }
    
}