class Solution {
public:
    int countMonobit(int n) {
        int cnt=0;
        n++;
        while(n>0){
            n=n/2;
            cnt++;
        }
        return cnt;
    }
};