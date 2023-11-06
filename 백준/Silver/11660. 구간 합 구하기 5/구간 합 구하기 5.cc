#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin >> N >> M;
    
    vector<vector<int>> num(N+1, vector<int>(N+1,0));
    vector<vector<int>> pf(N+1, vector<int>(N+1,0));
    
    for(int i=1; i<=N; i++){
        for(int k=1; k<=N; k++){
            cin >> num[i][k];
            pf[i][k] = pf[i][k-1] + pf[i-1][k] - pf[i-1][k-1] + num[i][k];
        }
    }
    
    for(int i=0; i<M; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int res = pf[x2][y2] - pf[x2][y1-1] - pf[x1-1][y2] + pf[x1-1][y1-1];
        cout << res << "\n";
    }
    
}