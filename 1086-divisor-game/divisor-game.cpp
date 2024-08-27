class Solution {
public:
    bool divisorGame(int n) {
        n--;
        if(n%2==1)return  true;
        else return false;
    }
};