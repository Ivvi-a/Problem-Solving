import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] skil = new int[N];
        int[] ans = new int[N + 1];

        for (int i = 0; i < N; i++) {
            skil[i] = Integer.parseInt(st.nextToken());
        }

        int num = N;
        int idx1 = 0;
        int idx2 = 1;
        int idx3 = N - 1;

        for (int i = 0; i < N; i++) {
            int init = skil[i];

            if (init == 1) {
                ans[idx1] = num;
                if (ans[idx1+1] == 0) {
                    idx1+=1;
                } else {
                    idx1 = idx2 + 1;
                }
            } else if (init == 2) {
                if (ans[idx1 + 1] == 0) {
                    idx2 = idx1 + 1;
                } else {
                    idx2+=1;
                }
                ans[idx2] = num;
            } else {
                ans[idx3] = num;
                idx3-=1;
            }
            num-=1;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(ans[i] + " ");
        }

        System.out.println(sb);

    }
}