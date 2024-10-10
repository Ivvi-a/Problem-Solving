import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        while(true){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(a == 0){
                break;
            }

            if(a < b && b%a == 0) {
                System.out.println("factor");

            }
            else if(a > b && a%b == 0){
                System.out.println("multiple");
            }
            else{
                System.out.println("neither");
            }
        }

    }
}