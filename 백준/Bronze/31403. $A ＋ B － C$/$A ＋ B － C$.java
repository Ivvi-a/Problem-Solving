import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int A = input();
        int B = input();
        int C = input();

        System.out.println(A+B-C);

        String AB = Integer.toString(A) + Integer.toString(B);

        System.out.println(Integer.parseInt(AB)-C);
    }


    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}