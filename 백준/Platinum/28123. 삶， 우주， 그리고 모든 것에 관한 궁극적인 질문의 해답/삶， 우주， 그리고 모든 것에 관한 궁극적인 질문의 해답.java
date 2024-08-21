import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = input(st);
        long k = input(st);
        int x = (int) input(st);

        long[] seq = {0,1,2,2,3,3,3,3,4,4};
        long lastInCycle = 0;

        if(x == 4 || x == 8 || x == 9){
            lastInCycle = n + (4 - seq[x]);
        }
        else{
            lastInCycle = n + (3 - seq[x]);
        }

        System.out.println(lastInCycle+1-(k*3));

    }

    static long input(StringTokenizer st){
        return Long.parseLong(st.nextToken());
    }
}