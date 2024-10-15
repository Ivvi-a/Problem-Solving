import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());
        ArrayList<Integer> li = new ArrayList<>();
        while(N-->0){
            li.add(Integer.parseInt(br.readLine()));
        }
        Collections.sort(li);
        for(Integer i : li){
            System.out.println(i);
        }
    }

}