import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int N = input();
        BigInteger res = new BigInteger("1");

        while(N>0){
            res = res.multiply(BigInteger.valueOf(N--));
        }

        int cnt = 0;
        BigInteger num = new BigInteger("1");
        while(true){
            if(res.mod(num.multiply(BigInteger.valueOf(10))).equals(BigInteger.valueOf(0))){
                cnt++;
                num = num.multiply(BigInteger.valueOf(10));
            }
            else{
                break;
            }
        }

        System.out.println(cnt);

    }


    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}