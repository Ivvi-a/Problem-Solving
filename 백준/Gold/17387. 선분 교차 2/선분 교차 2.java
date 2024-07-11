import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        long[] X = new long[4];
        long[] Y = new long[4];

        // 입력받기
        for(int i=0; i<=2; i+=2){
            st = new StringTokenizer(br.readLine());
            for(int k=0; k<2; k++){
                X[i+k] = Long.parseLong(st.nextToken());
                Y[i+k] = Long.parseLong(st.nextToken());
            }
        }

        // 계산
        if(isCross(X[0], Y[0], X[1], Y[1], X[2], Y[2], X[3], Y[3])){
            System.out.print(1);
        }
        else{
            System.out.print(0);
        }

    }

    // 선분 교차 여부
    static boolean isCross(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4){
        int abc = CCW(x1, y1, x2, y2, x3, y3);
        int abd = CCW(x1, y1, x2, y2, x4, y4);
        int cda = CCW(x3, y3, x4, y4, x1, y1);
        int cdb = CCW(x3, y3, x4, y4, x2, y2);

        if(abc * abd == 0 && cda * cdb == 0){
            return isOverlab(x1, y1, x2, y2, x3, y3, x4, y4);
        }
        else if(abc * abd <= 0 && cda * cdb <= 0){
            return true;
        }
        else{
            return false;
        }
    }

    static boolean isOverlab(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4){
        if(Math.min(x1, x2) <= Math.max(x3, x4) && Math.min(x3, x4) <= Math.max(x1, x2) && Math.min(y1, y2) <= Math.max(y3, y4) && Math.min(y3, y4) <= Math.max(y1, y2)){
            return true;
        }
        else{
            return false;
        }
    }

    // CCW
    static int CCW(long x1, long y1, long x2, long y2, long x3, long y3){
        long res = (x1 *y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);

        if(res > 0){
            return 1;
        }
        else if(res < 0){
            return -1;
        }
        else{
            return 0;
        }
    }
}