class Solution {
public:
    bool isPowerOfThreeHelper(int n){
        cout<<n<<endl;
        if(n<=0) return false;
        if(n==1) return true;
        if(n%3!=0) return false;
        return isPowerOfThreeHelper(n/3);
    }
    bool isPowerOfThree(int n) {
        return isPowerOfThreeHelper(n);
        
    }
};