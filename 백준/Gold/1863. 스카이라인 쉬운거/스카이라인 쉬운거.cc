#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int ans = 0;

	stack<int> stack;
	stack.push(0);

	while (n--) {
		int x, y;
		cin >> x >> y;
		if (stack.top() < y) {
			stack.push(y);
		}
		else {
			while (stack.top() > y) {
				stack.pop();
				ans++;
			}
			if (stack.top() != y) {
				stack.push(y);
			}
		}
	}

	ans += stack.size() - 1;

	cout << ans;

	return 0;
}