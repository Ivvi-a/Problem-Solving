#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    for (int t = 0; t < T; t++) {
        int Q; cin >> Q;
        multiset<int> s;

        for (int q = 0; q < Q; q++) {
            char query; int n;
            cin >> query >> n;
            if(query == 'I'){
                s.insert(n);
            }
            else if (!s.empty() && n == 1) {
                s.erase(prev(s.end()));
            }
            else if(!s.empty() && n == -1){
                s.erase(s.begin());
            }
        }
        if (s.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *prev(s.end()) << " " << *s.begin() << "\n";
        }
    }
    return 0;
}