import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int[] X = new int[3];
        int[] Y = new int[3];

        // 입력받기
        for (int i = 0; i <= 2; i++) {
            st = new StringTokenizer(br.readLine());
            X[i] = Integer.parseInt(st.nextToken());
            Y[i] = Integer.parseInt(st.nextToken());
        }

        // CCW
        int ccw = (X[0]*Y[1] + X[1]*Y[2] + X[2]*Y[0]) - (X[1]*Y[0] + X[2]*Y[1] + X[0]*Y[2]);

        if(ccw > 0){
            System.out.print(1);
        }
        else if(ccw < 0){
            System.out.print(-1);
        }
        else{
            System.out.print(0);
        }

    }
}