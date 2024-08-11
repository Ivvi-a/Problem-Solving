import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N,T,P;
    static int[] applicant = new int[6];

    public static void main(String[] args) throws IOException {
        N = input(); // 참가자 수

        // 사이즈별 신청자 수
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 6; i++) {
            applicant[i] = input(st);
        }

        st = new StringTokenizer(br.readLine());
        T = input(st); // 티셔츠 - 한 묶음 개수
        P = input(st); // 펜 - 한 묶음 개수

        // applicant 몫+1의 합
        int res = 0;
        for (int i = 0; i < 6; i++) {
            if(applicant[i]%T == 0){
                res += applicant[i]/T;
            }
            else{
                res += applicant[i]/T + 1;
            }
        }
        System.out.println(res);

        // 참가자 수/펜 묶음 수 -> 몫과 나머지
        System.out.printf("%d %d", N/P, N%P);

    }

    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}