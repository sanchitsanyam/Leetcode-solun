//https://youtu.be/VjL8mlof27k?si=x-AicRExMt2WUwzU
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        int opn=0;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            while(s.top()>nums[i])s.pop();
            opn += ((nums[i]!=0)&&(s.top()<nums[i]));
            s.push(nums[i]);
        }
        return opn;
        
    }
};