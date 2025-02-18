#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string str; cin >> str;
    set<string> s;
    for (int len = 1; len <= str.length(); len++) {
        for (int i = 0; i <= str.length() - len; i++) {
            s.insert(str.substr(i, len));
        }
    }
    cout << s.size();
    return 0;
}