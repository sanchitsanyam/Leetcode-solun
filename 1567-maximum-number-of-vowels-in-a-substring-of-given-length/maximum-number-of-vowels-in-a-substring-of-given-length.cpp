class Solution {
public:
    int maxVowels(string s, int k) {
        int c=0;
        int max=INT_MIN;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                c++;
            }
        }
        max=c;
        int n=s.length();
        for(int i=1;i<=n-k;i++){
            if(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u'){
                c--;
            }
            if(s[i+k-1]=='a'||s[k+i-1]=='e'||s[k+i-1]=='i'||s[i+k-1]=='o'||s[i+k-1]=='u'){
                c++;
            }
            if(c>max){
                max=c;
            }

        }
        
        return max;
        
    }
};
