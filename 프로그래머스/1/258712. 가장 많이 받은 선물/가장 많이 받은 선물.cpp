#include <string>
#include <sstream>
#include <vector>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    // gift : 준 받은
    // 선물지수 : 준 - 받은
    
    vector<vector<int>> diff(friends.size(), vector<int>(friends.size(),0));
    vector<int> giftScore(friends.size(),0);
    
    for(int i=0; i<gifts.size(); i++){
        string str = gifts[i];
        istringstream ss(str);
        string sub;
        vector<int> name;
        
        while(getline(ss, sub, ' ')){
            for(int k=0; k<friends.size(); k++){
                if(friends[k].compare(sub) == 0){
                    name.push_back(k);
                }
            }
        }
        
        // 두 사람의 관계 : diff[준 사람][받은 사람]
        diff[name[0]][name[1]]++;

        // 선물 지수 : 모든 사람의 선물 지수 구하기 (준+1 받은-1)
        giftScore[name[0]]++;
        giftScore[name[1]]--;
    }
    
    // 모든 사람이 선물을 몇개 받게 되는지 구하기
    int answer = 0;
    
    for(int i=0; i<friends.size(); i++){
        int get = 0;
        
        for(int k=0; k<friends.size(); k++){
            if(i==k) continue; // 자신일때 넘기기
            
            // 우선 순위
            // 1. 선물 주고 받은 기록 O -> 더 많이 "준" 사람이 받음
            if(diff[i][k] > diff[k][i]){
                get++;
            }
            // 2. 선물 주고 받은 기록 x, "준"이 같음 -> 선물 지수 큰 사람이 받음
            else if(diff[i][k] == diff[k][i] && giftScore[i] > giftScore[k]){
                get++;
            }
        }
        answer = max(answer,get);
    }
    
    
    return answer;
}