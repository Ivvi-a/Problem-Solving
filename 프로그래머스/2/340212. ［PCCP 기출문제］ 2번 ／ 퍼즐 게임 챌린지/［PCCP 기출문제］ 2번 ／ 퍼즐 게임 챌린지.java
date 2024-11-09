class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        int len = diffs.length;
        int start = 1;
        int end = 100000;
        
        while(start <= end){
            int mid = (start+end)/2; // level
            // calc times
            long time = 0;
            for(int i=0; i<len; i++){
                if(mid >= diffs[i]){
                    time += times[i];
                }
                else{
                    time += (diffs[i]-mid)*(times[i]+times[i-1]) + times[i]; // max-2000010000under
                }
                if(time > limit){
                    break;
                }
            }
            if(time == limit){
                answer = mid;
                break;
            }
            else if(time < limit){
                end = mid - 1;
                answer = mid;
            }
            else{
                start = mid + 1;
            }
        }
        
        return answer;
    }
}