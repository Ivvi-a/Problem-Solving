public class Main {
    static int node = 100; // 노드 수
    static int[] parent = new int[node+1];
    public static void main(String[] args) {
        // 부모 배열 초기화
        for(int i=1; i<=node; i++){
            parent[i] = i;
        }

        // 연결할 수를 입력받아 유니온 연산
        int ex1 = 1;
        int ex2 = 2;
        union(1,2);
    }

    static void union(int a, int b){
        int a_parent = find(a);
        int b_parent = find(b);

        if(a_parent < b_parent){
            parent[b] = a_parent; // 대표 노드끼리 연결
        }
        else if(a_parent > b_parent){
            parent[a] = b_parent;
        }
    }

    static int find(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = find(parent[n]); // 재귀
    }
}
