import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N,M;
    static int[] num, tree;

    static void solve() throws IOException {
        makeTree(1,N,1);

        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int cmd = input(st);
            int a = input(st);
            int b = input(st);

            switch (cmd){
                case 1:
                    updateTree(1,N,1,a,b);
                    break;
                case 2:
                    bw.write(query(1,N,1,a,b)+"\n");
            }
        }
    }

    static int makeTree(int start, int end, int node){
        if(start == end){
            return tree[node] = num[start];
        }
        int mid = (start+end)/2;

        return tree[node] = Math.min(makeTree(start,mid,node*2), makeTree(mid+1,end,(node*2)+1));
    }

    static int updateTree(int start, int end, int node, int idx, int val){
        if(idx > end || idx < start) return tree[node];

        if(start==end) return tree[node] = val;

        int mid = (start+end)/2;
        return tree[node] = Math.min(updateTree(start,mid,node*2,idx,val),updateTree(mid+1,end,(node*2)+1,idx,val));
    }

    static int query(int start, int end, int node, int left, int right){
        if(left > end || right < start) return Integer.MAX_VALUE;

        if(left <= start && right >= end) return tree[node];

        int mid = (start+end)/2;
        return Math.min(query(start,mid,node*2,left,right), query(mid+1,end,(node*2)+1,left,right));
    }

    public static void main(String[] args) throws IOException {
        N = input();
        num = new int[N+1];
        tree = new int[4*N];

        st = new StringTokenizer(br.readLine());
        for(int i=1; i<=N; i++){
            num[i] = input(st);
        }

        M = input();

        solve();

        bw.flush();
        bw.close();
    }

    // -----------

    static int input() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    static int input(StringTokenizer st) throws IOException {
        return Integer.parseInt(st.nextToken());
    }

}