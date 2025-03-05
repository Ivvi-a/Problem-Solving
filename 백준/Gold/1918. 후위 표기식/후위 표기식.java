import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		String str = sc.next(); // 중위 표기식
		Stack<Character> stack = new Stack<>(); // 연산자 스택
		StringBuilder sb = new StringBuilder(); // 후위 표기식
		
		for(int i=0; i<str.length(); i++) {
			char c = str.charAt(i);
			// c = 피연산자
			if(c>='A' && c<='Z') {
				sb.append(c);
			}
			// c = 괄호
			else if(c=='(') {
				stack.push(c);
			}
			else if(c==')') {
				while(stack.peek()!='(') {
					sb.append(stack.pop());
				}
				stack.pop(); // 여는 괄호 버리기
			}
			// c = 연산자
			else {
				if(stack.isEmpty()) {
					stack.push(c);
				}
				// 우선 순위가 높은 경우
				else if(pri(c)>pri(stack.peek())) {
					stack.push(c);
				}
				// 우선 순위가 낮은 경우
				else {
					while(!(stack.isEmpty() || pri(c)>pri(stack.peek()))) {
						sb.append(stack.pop());
					}
					stack.push(c);
				}
			}
		}
		// 모든 수식 사용 -> 스택이 빌 때까지 pop
		while(!stack.isEmpty()) {
			sb.append(stack.pop());
		}
		// 출력
		System.out.println(sb);	
	}
	
	// 연산자 우선순위 리턴
		public static int pri(char c) {
			if(c=='(' || c==')') {
				return 0;
			}
			else if(c=='+' || c=='-') {
				return 1;
			}
			else if(c=='*' || c=='/') {
				return 2;
			}
			return -1;
		}

}
