class Solution {
    public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
        int answer = 0;
        int time = (h2*3600 + m2*60 + s2) - (h1*3600 + m1*60 + s1);
        
        //12h: 43200s -> 43200을 기준 단위로 위치 계산
        h1 = (h1*3600 + m1*60 + s1)%43200; 
        h2 = (h2*3600 + m2*60 + s2)%43200;
        m1 = m1*720 + s1*12;
        m2 = m2*720 + s2*12;
        s1 *= 720;
        s2 *= 720;
 
        int hb = 0;
        int mb = 0;
        int sb = 0;
                
        while(time-->=0){
            if(h1 == s1 && m1 == s1) answer++; // 0시, 12시 정각
            else{
                if(hb > sb && (h1 <= s1 || s1 == 0)) answer++; // 초침 -> 시침
                if(mb > sb && (m1 <= s1 || s1 == 0)) answer++; // 초침 -> 분침
            }
            // 현재 위치 저장
            hb = h1;
            mb = m1;
            sb = s1;
            // 1초 후 위치 계산
            h1 = (h1+1)%43200;
            m1 = (m1+12)%43200;
            s1 = (s1+720)%43200;
        }
        return answer;
    }
}