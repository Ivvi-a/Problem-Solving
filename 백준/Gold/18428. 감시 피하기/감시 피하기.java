import java.io.*;
import java.util.*;

class Node{
    int x;
    int y;
    public Node(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static String[][] arr;
    static boolean[][] sight, obj;
    static List<Node> teacher = new ArrayList<>();
    static List<Node> student = new ArrayList<>();
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new String[N][N];
        sight = new boolean[N][N];
        obj = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            arr[i] = str.split(" ");
            for(int k=0; k<N; k++){
                if(arr[i][k].equals("S")){
                    student.add(new Node(i,k));
                }
                else if(arr[i][k].equals("T")){
                    teacher.add(new Node(i,k));
                }
            }

        }
        ICU();
        putObj(0);
        System.out.println("NO");
    }
    static boolean isOkay(){
        for(Node t : teacher){
            for(int d=0; d<4; d++){
                int n = 1;
                while(true){
                    int nx = t.x + n*dx[d];
                    int ny = t.y + n*dy[d];
                    if(nx>=0 && ny>=0 && nx<N && ny<N){
                        if(obj[nx][ny]) break;
                        if(arr[nx][ny].equals("S")) return false;
                        n++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return true;
    }

    static void putObj(int cnt){
        if(isOkay()){
            System.out.println("YES");
            System.exit(0);
        }
        if(cnt == 3) return;

        for(int i=0; i<N; i++){
            for(int k=0; k<N; k++){
                if(arr[i][k].equals("X")&& sight[i][k] && !obj[i][k]){
                    obj[i][k] = true;
                    putObj(cnt+1);
                    obj[i][k] = false;
                }
            }
        }
    }

    static void ICU(){
        for(Node t : teacher){
            for(Node s : student){
                if(t.x == s.x){
                    if(Math.abs(t.y-s.y)==1){
                        System.out.println("NO");
                        System.exit(0);
                    }
                    if(t.y > s.y){
                        for(int i=s.y+1; i<t.y; i++){
                            sight[t.x][i] = true;
                        }
                    }
                    else{
                        for(int i=t.y+1; i<s.y; i++){
                            sight[t.x][i] = true;
                        }
                    }
                }
                else if(t.y == s.y){
                    if(Math.abs(t.x-s.x)==1){
                        System.out.println("NO");
                        System.exit(0);
                    }
                    if(t.x > s.x){
                        for(int i=s.x+1; i<t.x; i++){
                            sight[i][t.y] = true;
                        }
                    }
                    else{
                        for(int i=t.x+1; i<s.x; i++){
                            sight[i][t.y] = true;
                        }
                    }
                }
            }
        }
    }
}