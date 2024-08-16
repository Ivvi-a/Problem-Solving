import java.io.*;
import java.util.*;

class Node implements Comparable<Node>{
    int x;
    int y;

    public Node(int x, int y){
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Node n) {
        if(this.x == n.x){
            return this.y - n.y;
        }
        return this.x - n.x;
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        int N = input(); // 점의 개수

        ArrayList<Node> list = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = input(st);
            int y = input(st);
            list.add(new Node(x, y));
        }

        // 정렬
        Collections.sort(list);

        for (int i = 0; i < N; i++) {
            Node n = list.get(i);
            System.out.println(n.x+" "+n.y);
        }

    }


    // 읽기
    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }
    static int input(StringTokenizer st){
        return Integer.parseInt(st.nextToken());
    }
}