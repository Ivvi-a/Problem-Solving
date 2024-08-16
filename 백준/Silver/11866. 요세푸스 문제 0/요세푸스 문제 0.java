import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = input(st);
        int K = input(st);

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            q.add(i);
        }

        System.out.print("<");
        int cnt = 1;
        while(!q.isEmpty()){
            int num = q.poll();
            if(q.isEmpty()){
                System.out.print(num);
            }
            else if(cnt%K == 0){
                System.out.print(num+", ");
            }
            else{
                q.add(num);
            }
            cnt++;
        }
        System.out.print(">");

    }


    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}