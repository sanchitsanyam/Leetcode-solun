class Solution {
public:
    int binary_search(vector<int>& a, int n1,int n2,int t){
       if(n1<=n2){
        
            int l=n1;
            int e=n2;
            int r;
            r=(l+e)/2;
            if(a[r]==t){
                return r;
            }
            else if(a[r]>t){
                return binary_search(a,l,r-1,t);
            }
            else{
                return binary_search(a,r+1,e,t);
            }
       }    
        return -1;

    }
    int search(vector<int>& a, int t) {
    
        int n=a.size();
        
        int l=0;
        int e=n-1;
        
       
        return binary_search( a, l,e,t);
    }    
};