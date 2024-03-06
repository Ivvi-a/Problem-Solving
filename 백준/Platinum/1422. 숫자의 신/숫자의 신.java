import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()); // 1
        int K = Integer.parseInt(st.nextToken()); // 가지고 있는 수의 개수
        int N = Integer.parseInt(st.nextToken()); // 사용할 수의 개수

        // 수 입력 받기
        List<String> list = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        for(int i=0; i<K; i++){
            String str = br.readLine();
            list.add(str);
            temp.add(Integer.parseInt(str));
        }

        Collections.sort(temp);
        int n = N-K;
        for(int i=0; i<n; i++){
            list.add(String.valueOf(temp.get(temp.size()-1)));
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

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<list.size(); i++){
            sb.append(list.get(i));
        }
        System.out.println(sb);


        br.close();
    }

}

