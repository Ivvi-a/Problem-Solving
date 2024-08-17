import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] arr = new int[15][15];

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = input(st);
        int B = input(st);
        int V = input(st);

        int ans = (V-A)/(A-B)+1;

        if((V-A)%(A-B)!=0){
            ans++;
        }

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