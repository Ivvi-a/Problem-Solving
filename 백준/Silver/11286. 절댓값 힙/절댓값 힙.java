import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.io.BufferedReader;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()); // 연산 개수
        
        // 우선순위 큐
        PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                int a = Math.abs(o1);
                int b = Math.abs(o2);
                if(a==b){ // 3 -3   -4  4
                    return o1-o2;
                }
                return a-b;
            }
        });

        // 연산 수행
        for(int i=0; i<N; i++){
            int cmd = Integer.parseInt(br.readLine());
            if(cmd==0){
                if(pq.isEmpty()){
                    System.out.println(0);
                }
                else{
                    System.out.println(pq.poll());
                }
            }
            else{
                pq.offer(cmd);
            }
        }

    }
}