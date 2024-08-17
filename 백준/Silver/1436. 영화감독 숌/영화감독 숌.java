import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BigInteger MOD = new BigInteger("1234567891");

    public static void main(String[] args) throws IOException {
        int N = input();
        int num = 666;
        int ans = 0;

        while(N>0){
            if(Integer.toString(num).contains("666")){
                N--;
                ans = num;
            }
            num++;
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