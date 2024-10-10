import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] dots = new int[16];

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());
        dots[0] = 2;
        for (int i = 1; i <= N; i++) {
            dots[i] = 2* dots[i-1] - 1;
        }

        System.out.println(dots[N] * dots[N]);

    }
}