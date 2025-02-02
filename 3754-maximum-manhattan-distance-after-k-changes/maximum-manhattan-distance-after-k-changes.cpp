class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;
        for(char hor :{'E','W'}){
            for(char ver:{'N','S'}){
                int remk=k ,netX=0,netY=0;
                for(char ch :s){
                    if(ch== hor && remk){
                        ch=(ch=='W')?'E':'W';
                        remk--;
                    }
                    if(ch==ver && remk){
                        ch=(ch=='N')?'S':'N';
                        remk--;
                    }
                    netX+=(ch=='N');
                    netX-=(ch=='S');
                    netY+=(ch=='E');
                    netY-=(ch=='W');
                    ans=max(ans,abs(netX)+abs(netY));
                }
            }
        }
        return ans;
    }
};