import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] dots = new int[16];

    public static void main(String[] args) throws IOException {
        int X = Integer.parseInt(br.readLine());
        int n = 1;

        while(true){
            if(X-n <= 0){
                break;
            }
            else{
                X -= n;
                n++;
            }
        }

        int a;
        int b;

        if(n%2 == 1){
            a = n;
            b = 1;
            while(X-->1){
                a--;
                b++;
            }
        }
        else{
            a = 1;
            b = n;
            while(X-->1){
                a++;
                b--;
            }
        }

        System.out.println(a+"/"+b);

    }
}