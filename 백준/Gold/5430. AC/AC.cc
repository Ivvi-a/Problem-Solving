#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


bool R(bool isReversed) {
    return !isReversed;
}

void D(vector<int>& v, bool isReversed) {
    if (isReversed) {
        v.pop_back();
    }
    else {
        v.erase(v.begin());
    }   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        string cmds; cin >> cmds;
        int n; cin >> n;
        string arr; cin >> arr;

        // 배열 저장
        arr = arr.substr(1, arr.size() - 2);
        stringstream ss(arr);
        string num;
        vector<int> v;
        while (getline(ss, num, ',')) {
            v.push_back(stoi(num));
        }

        // 수행
        bool isReversed = false;
        bool isError = false;
        for (int i = 0; i < cmds.length(); i++) {
            char cmd = cmds[i];
            if (cmd == 'R') {
                isReversed = R(isReversed);
            }
            else {
                if (v.empty()) {
                    isError = true;
                    break;
                }
                D(v, isReversed);
            }
        }

        // 출력
        if (isError) cout << "error\n";
        else {
            cout << "[";
            if (isReversed) {
                for (int i = v.size()-1; i >= 0 ; i--) {
                    cout << v[i];
                    if (i != 0) cout << ",";
                }
            }
            else {
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i];
                    if (i != v.size()-1) cout << ",";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}