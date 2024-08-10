import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N,M;
    static int minCount = 64;
    static int edge[] = new int[3];

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        loop: while(true){
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 3; i++) {
                edge[i] = input(st);
                if(edge[i] == 0){
                    break loop;
                }
            }
            Arrays.sort(edge);

            if(Math.pow(edge[0],2) + Math.pow(edge[1],2) == Math.pow(edge[2],2)){
                sb.append("right\n");
            }else {
                sb.append("wrong\n");
            }

        }
        System.out.println(sb);
    }

    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}