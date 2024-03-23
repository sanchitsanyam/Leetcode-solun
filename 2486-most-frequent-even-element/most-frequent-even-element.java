class Solution {
    public int mostFrequentEven(int[] nums) {
        HashMap<Integer,Integer> freq=new HashMap<>();
        for(int num: nums){
            freq.put(num,freq.getOrDefault(num,0)+1);
        }
        int maxFreqSoFar=0,finalAns=-1;
        for(Integer num:freq.keySet()){
            int curFreq=freq.get(num);
            if(num%2==1 || curFreq< maxFreqSoFar){
                continue;
            }
            if(curFreq>maxFreqSoFar||num<finalAns){
                maxFreqSoFar=curFreq;
                finalAns=num;
            }
        }
        return finalAns;
    }
}