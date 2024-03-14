class Solution {
public:
    //competitor function
    bool static sorted(const vector<int>&v1,const vector<int>&v2){
        if(v1[1]==v2[1]){
            return v1[0]>=v2[0];
        }
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),sorted);  
        int j=0,n=0,ans=0;
        cout<<j-1<<endl;
        int total_boxes=0,total_weight=0;
        for(int i=0;i<boxTypes.size();i++){
           total_boxes+=boxTypes[i][0];
           total_weight+=boxTypes[i][0]*boxTypes[i][1];
        }
        cout<<total_boxes<<endl;
        cout<<total_weight<<endl;
        while(truckSize>n && j<boxTypes.size()){
            n+=boxTypes[j][0];
            cout<<n<<" ";
            ans+=boxTypes[j][0]*boxTypes[j][1];
            cout<<ans<<" ";
            j++;
            cout<<j-1<<endl;
        }
        cout<<n<<" "<<ans<<endl;
        if( n<=truckSize && total_boxes==n && ans<=total_weight )return ans;
        ans+=(truckSize-n)*boxTypes[j-1][1];
        cout<<ans<<" "<<j-1;
        return ans;
        

    }
};