import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int M = Integer.parseInt(br.readLine());
		
		int[] num = new int[21];
		
		// 명령 수행
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			String cmd = st.nextToken();
			
			if(cmd.equals("add")) {
				int n = Integer.parseInt(st.nextToken());
				if(num[n]==0) num[n] = 1;
			}
			
			else if(cmd.equals("remove")) {
				int n = Integer.parseInt(st.nextToken());
				if(num[n]==1) num[n] = 0;
			}
			
			else if(cmd.equals("check")) {
				int n = Integer.parseInt(st.nextToken());
				if(num[n]==1) sb.append(1+"\n");
				else sb.append(0+"\n");
			}
			
			else if(cmd.equals("toggle")) {
				int n = Integer.parseInt(st.nextToken());
				if(num[n]==1) num[n] = 0;
				else if(num[n]==0) num[n] = 1;
			}
			
			else if(cmd.equals("all")) {
				for(int k=1; k<=20; k++) {
					num[k] = 1;
				}
			}
			
			else {
				for(int k=1; k<=20; k++) {
					num[k] = 0;
				}
			}
			
		}
		
		System.out.println(sb);
		
	}

}
