import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String N = br.readLine();
        Integer[] arr = new Integer[N.length()];

        for (int i = 0; i < N.length(); i++) {
            arr[i] = Character.getNumericValue(N.charAt(i));
        }

        Arrays.sort(arr, Collections.reverseOrder());

        for(Integer n : arr){
            System.out.print(n);
        }
    }

}