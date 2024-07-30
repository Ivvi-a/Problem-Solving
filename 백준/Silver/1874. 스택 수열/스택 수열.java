import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int n;
    static int[] seq;

    public static void main(String[] args) throws IOException {
        n = input();
        seq = new int[n];
        for(int i=0; i<n; i++){
            seq[i] = input();
        }

        // idx = 0으로 시작
        // 1부터 스택에 push한다
        // top == seq[idx]일 때, pop한다
        // idx++

        StringBuilder sb = new StringBuilder();
        int idx = 0;
        Stack<Integer> stack = new Stack<>();

        for(int i=1; i<=n; i++){
            stack.push(i);
            sb.append("+\n");
            while(true){
                if(!stack.isEmpty() && stack.peek() == seq[idx]){
                    stack.pop();
                    idx++;
                    sb.append("-\n");
                }
                else{
                    break;
                }
            }
        }

        // 정답 출력
        if(!stack.isEmpty()){
            System.out.println("NO");
        }
        else{
            System.out.println(sb);
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