import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken()); // 수열 길이
		int S = Integer.parseInt(st.nextToken()); // 목표 부분합
		
		// 배열 입력받기
		st = new StringTokenizer(br.readLine());
		
		int[] arr= new int[N];
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		// 부분합 구하기
        int min = N+1;
		
		for(int start=0; start<N; start++) {
			int end = start;
			int sum = 0;
			a: while(end<N) {
				sum+=arr[end];
				if(sum>=S) {
					if(end-start+1<min) {
						min = end-start+1;	
					}
					sum-=arr[start];
					break a;
				}
				end++;
			}
		}
		
		// 출력
		if(min!=N+1) {
			System.out.println(min);
		}
		else {
			System.out.println(0);
		}
		
		
		
	}

}
