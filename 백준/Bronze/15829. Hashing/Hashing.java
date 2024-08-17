import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BigInteger MOD = new BigInteger("1234567891");

    public static void main(String[] args) throws IOException {
        int L = input();
        String str = br.readLine();

        BigInteger ans = new BigInteger("0");
        BigInteger hash = new BigInteger("1");

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            ans = ans.add(BigInteger.valueOf(c-96).multiply(hash));
            ans = ans.mod(MOD);
            hash = hash.multiply(BigInteger.valueOf(31));
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