#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // c++ 입출력 버퍼와 c 입출력 버퍼 동기화 xor
    cout.tie(NULL);
    cin.tie(NULL); // 입출력 스트림의 버퍼와 연결 끊기

    int N,M;
    
    cin >> N >> M;
    int list[N+1];
    list[0] = 0;
    for(int i=1; i<N+1; i++){
        int n;
        cin >> n;
        list[i] = list[i-1]+n;
    }
    
    for(int i=0; i<M; i++){
        int s,e;
        cin >> s >> e;
        cout<< list[e] - list[s-1] << "\n";
    }
    
    return 0;
}