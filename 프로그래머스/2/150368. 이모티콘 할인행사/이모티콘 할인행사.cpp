#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxMember, maxSell;
vector<int> d_user[5];
vector<int> sum;
vector<int> limit;

void dfs(vector<int>& emoticons, int depth);

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    // 할인율 : 10 20 30 40
    // users(1~100) : [할인율 가격]
    // emoticons(1~7) : 가격
    // 4^7 = 약 16000 -> 따라서 모든 경우의 수 계산해보기 가능
    
    // 유저 분류
    for(int i=0; i<users.size(); i++){
        int ratio = users[i][0];
        // cout << (ratio-1)/10 << "\n";
        d_user[(ratio-1)/10].push_back(i);
        limit.push_back(users[i][1]);
    }
    
    sum = vector<int>(limit.size(),0);
    
    dfs(emoticons, 0);
    
    answer.push_back(maxMember);
    answer.push_back(maxSell);
    
    return answer;
}

void dfs(vector<int>& emoticons, int depth){
    if(depth == emoticons.size()){
        // plus 가입 유저 / 이모티콘 판매액 계산
        int member = 0;
        int sell = 0;
        for(int u=0; u<sum.size(); u++){
            if(sum[u] >= limit[u]){
                member++;
            }
            else{
                sell += sum[u];
            }
        }
        // 최댓값 갱신
        if(member > maxMember){
            maxMember = member;
            maxSell = sell;
        }
        else if(member == maxMember && sell > maxSell){
            maxSell = sell;
        }
        
        return;
    }
    
    int nowCost = emoticons[depth];
    
    for(int i=1; i<=4; i++){
        int cost = nowCost * (100 - i*10) / 100;
        // cout << "cost : " << cost << "\n";
        
        for(int k=0; k<i; k++){
            vector<int> buyers = d_user[k];
            // buyer.cost += cost
            for(int j=0; j<buyers.size(); j++){
                sum[buyers[j]] += cost;
            }
        }
        
        dfs(emoticons, depth+1);
        
        for(int k=0; k<i; k++){
            vector<int> buyers = d_user[k];
            // buyer.cost += cost
            for(int j=0; j<buyers.size(); j++){
                sum[buyers[j]] -= cost;
            }
        }
    }
}