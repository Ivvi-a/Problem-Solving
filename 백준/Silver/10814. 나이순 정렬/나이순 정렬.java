import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        int N = input(); // 회원 수

        ArrayList<String>[] list = new ArrayList[201];
        for (int i = 1; i < list.length; i++) {
            list[i] = new ArrayList<>();
        }

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int age = input(st);
            String name = st.nextToken();

            list[age].add(name);
        }

        for (int i = 1; i < list.length; i++) {
            if(!list[i].isEmpty()){
                for (int j = 0; j < list[i].size(); j++) {
                    System.out.println(i+" "+list[i].get(j));
                }
            }
        }

    }


    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}