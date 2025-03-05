import java.util.*;
import java.io.*;

public class Main {
	// 변수
	static int N,ans;
	static int[] arr;
	
	// main
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt(); // 퀸 개수
		arr = new int[N+1];

		place(1);
		
		System.out.println(ans);
		
	}
	
	// 퀸 배치
	static void place(int depth) {
		// 카운트
		if(depth==N+1) {
			ans++;
			return;
		}
		
		// check하고 재귀
		for(int n=1; n<=N; n++) {
			arr[depth] = n;
			if(check(depth)) {
				place(depth+1);
			}
			
		}			
		
	}
	
	static boolean check(int depth) {
		for(int i=1; i<depth; i++) {
			if(arr[i]==arr[depth]) {
				return false;
			}
		}
		
		for(int i=1; i<depth; i++) {
			if(Math.abs(i-depth)==Math.abs(arr[i]-arr[depth])) {
				return false;
			}
		}
	
		return true;
		
	}		

}