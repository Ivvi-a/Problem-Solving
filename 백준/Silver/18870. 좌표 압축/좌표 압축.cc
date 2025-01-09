#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;
    set<int> s;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
        s.insert(n);
    }

    map<int, int> m;
    
    int idx = 0;
    for (auto a = s.begin(); a != s.end(); ++a) {
        m.insert({ *a, idx });
        idx++;
    }

    for (int i = 0; i < N; i++) {
        int n = v[i];
        cout << m[n] << " ";
    }
    
}