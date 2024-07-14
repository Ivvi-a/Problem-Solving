import java.util.*;

public class Main {

  static int[] arr;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
    int n = sc.nextInt();
    int m = sc.nextInt();

    // int list -> 크기: n+1
    arr = new int[n+1];
    Arrays.setAll(arr, k -> k);

    // union or find
    for(int i=0; i<m; i++){
      int t = sc.nextInt();
      int a = sc.nextInt();
      int b = sc.nextInt();

      // union
      if(t==0){
        union(a,b);
      }
      // find
      else if(t==1){
        if(find(a)==find(b)){
          System.out.println("YES");
        }
        else{
          System.out.println("NO");
        }
      }
    }
    sc.close();
  }
  
  public static void union(int x, int y){
    x = find(x);
    y = find(y);
    if(x > y){
      arr[x] = y;
    }else if(x < y){
      arr[y] = x;
    }
  }

  public static int find(int x){
    if(arr[x]==x) return x;
    return arr[x] = find(arr[x]);
    
  } 
}
