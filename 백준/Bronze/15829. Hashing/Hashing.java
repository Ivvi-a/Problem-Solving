import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int MOD = 1234567891;

    public static void main(String[] args) throws IOException {
        int L = input();
        String str = br.readLine();

        long ans = 0;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            ans += (long) ((c-96) * (Math.pow(31,i)%MOD));
        }

        ans %= MOD;

        System.out.println(ans);

    }


    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}