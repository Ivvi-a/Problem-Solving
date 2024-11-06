public class Main {
    public static void main(String[] args) throws IOException {
        int[] sortedArray = new int[10000];
        int target = 500;
        
        int startIdx = 0;
        int endIdx = sortedArray.length-1;

        while(start <= end){
            int midIdx = (startIdx + endIdx) / 2;
            int midElm = sortedArray[midIdx];

            if(midElm > target){
                endIdx = midIdx - 1;
            }
            else if(midElm < target){
                startIdx = midIdx + 1;
            }
            else{
                break; // find
            }
        }

    }
}
