import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] bingo = new int[5][5];
    static int ans = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // 빙고 입력받기
        for(int i=0; i<5; i++){
            st = new StringTokenizer(br.readLine());
            for(int k=0; k<5; k++){
                bingo[i][k] = Integer.parseInt(st.nextToken());
            }
        }

        // 빙고 지우기
        for(int i=0; i<5; i++){
            st = new StringTokenizer(br.readLine());
            for(int k=0; k<5; k++){
                int num = Integer.parseInt((st.nextToken()));
                erase(num);
                ans++;
            }
        }

    }

    // 숫자 지우기
    static void erase(int num){
        a: for(int i=0; i<5; i++){
            for(int k=0; k<5; k++){
                if(bingo[i][k] == num){
                    bingo[i][k] = 0;
                    break a;
                }
            }
        }

        isBingo();
    }

    // 빙고 판별
    static void isBingo(){
        int cnt = 0;

        // 가로
        for(int y=0; y<5; y++){
            for(int x=0; x<5; x++){
                if(bingo[y][x] !=0) break;
                if(bingo[y][x] == 0 && x == 4) cnt++;
            }
        }
        // 세로
        for(int x=0; x<5; x++){
            for(int y=0; y<5; y++){
                if(bingo[y][x] !=0) break;
                if (bingo[y][x] == 0 && y == 4) cnt++;
            }
        }

        // 대각선
        for(int i=0; i<5; i++){
            if(bingo[i][i] != 0) break;
            if (bingo[i][i] == 0 && i == 4) cnt++;
        }
        for(int i=0; i<5; i++){
            if(bingo[i][4-i] != 0) break;
            if (bingo[i][4-i] == 0 && i == 4) cnt++;
        }

        if(cnt >= 3){
            System.out.println(ans);
            System.exit(0);
        }
    }
}