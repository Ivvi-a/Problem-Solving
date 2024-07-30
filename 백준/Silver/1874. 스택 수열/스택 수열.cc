#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> seq(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    vector<char> res;
    int idx = 0;
    stack<int> stack;

    for (int i = 1; i <= n; i++) {
        stack.push(i);
        res.push_back('+');
        while (!stack.empty() && stack.top() == seq[idx]) {
            stack.pop();
            idx++;
            res.push_back('-');
        }
    }

    // 정답 출력
    if (!stack.empty()) {
        cout << "NO";
    }
    else {
        for (char c : res) {
            cout << c << "\n";
        }
    }

    return 0;

}