import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String S = sc.nextLine();
		String P = sc.nextLine();
		int sLen = S.length();
		int pLen = P.length();
		
		// table 생성
		int[] table = new int[pLen];
		int idx = 0;
		for(int i=1; i<pLen; i++) {
			while(idx>0 && P.charAt(i) != P.charAt(idx)){
				idx = table[idx-1];
			}
			
			if(P.charAt(i) == P.charAt(idx)) {
				idx++;
				table[i] = idx;
			}
		}
		
		// KMP
		int ans = 0;
		ArrayList<Integer> ansList = new ArrayList<>();
		
		idx = 0;
		for(int i=0; i<sLen; i++) {
			// 글자가 일치하지 않는 경우
			while(idx>0 && S.charAt(i) != P.charAt(idx)) {
				idx = table[idx-1];
			}
			
			// 글자가 일치하는 경우
			if(S.charAt(i) == P.charAt(idx)) {
				if(idx == pLen-1) { // 문자열 전체가 일치
					ans++;
					ansList.add(i-idx+1); // n번째이므로 +1해주기 (0부터 시작이 아니라 1부터 시작)
					
                    idx = table[idx];
				}
				else {
					idx++;
				}
			}
		}
		
		// 정답 출력
		StringBuilder sb = new StringBuilder();
		sb.append(ans).append("\n");
		for(int n : ansList) {
			sb.append(n).append(" ");
		}
		System.out.println(sb);
		
	}
}