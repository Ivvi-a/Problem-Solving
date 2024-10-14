import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N,K;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if(N%i == 0){
                cnt++;
                if(cnt == K){
                    System.out.println(i);
                }
            }
        }

        if(cnt < K){
            System.out.println(0);
        }
        
    }

}