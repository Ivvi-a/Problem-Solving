import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()); // 1
        StringTokenizer st = new StringTokenizer(br.readLine()); // 2
        br.close();
        
        // 수 입력받기
        List<String> list = new ArrayList<>();
        for(int i=0; i<N; i++){
            list.add(st.nextToken());
        }

        // 정렬
        list.sort(new Comparator<String>() {
            @Override
            public int compare(String a, String b) {
                BigInteger ab = new BigInteger(a + b);
                BigInteger ba = new BigInteger(b + a);

                return ba.compareTo(ab);
            }
        });

        // 출력
        if (list.get(0).equals("0")) {
            System.out.println(0);
        }
        else{
            StringBuilder sb = new StringBuilder();
            for(int i=0; i<list.size(); i++){
                sb.append(list.get(i));
            }
            System.out.println(sb);

        }

    }

}

