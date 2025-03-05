import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine()); // 용액의 수
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		// 배열 입력받기
		int[] arr = new int[N];	
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			
		}
		
		Arrays.sort(arr);
		
		// 투 포인터?
		int start = 0;
		int end = N-1;
		int min = Math.abs(arr[start]+arr[end]);
		int sIdx = start;
		int eIdx = end;
		
		while(start<N) {
			if(start==end) {
				break;
			}
					
			int sum = arr[start]+arr[end];
			
			// 최솟값 저장
			if(Math.abs(sum)<min) {
				min = Math.abs(sum);
				sIdx = start;
				eIdx = end;
			}
			
			// sum의 값에 따라
			if(sum<0) {
				start++; // sum이 커짐
							
			}
			else if(sum>0) {
				end--; // sum이 작아짐
			}
			
			else {
				System.out.println(arr[start]+" "+arr[end]);
				return;
			}
		}
		
		System.out.println(arr[sIdx]+" "+arr[eIdx]);
		
		
	}

}
