import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static ArrayList<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        N = input();
        for (int i = 0; i < N; i++) {
            list.add(input());
        }
        Collections.sort(list);

        int cut = (int) Math.round((float) N * 0.15);

        int sum = 0;
        for (int i = cut; i < N-cut; i++) {
            sum += list.get(i);
        }

        System.out.println(Math.round((float) sum / (N-(2*cut))));

    }

    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}