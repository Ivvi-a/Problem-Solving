import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] cons = new int[6];

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 6; i++) {
            cons[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = -999; i < 1000 ; i++) {
            for (int j = -999; j < 1000; j++) {
                if(cons[0] * i + cons[1] * j == cons[2] && cons[3] * i + cons[4] * j == cons[5]){
                    System.out.println(i+" "+j);
                    System.exit(0);
                }
            }
        }
    }
}