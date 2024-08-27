class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        int sum=0;
        for(int i=0;i<energy.size();i++){
            sum+=energy[i];
        }
        
        if(sum>=initialEnergy)ans+=sum-initialEnergy+1;
        cout<<ans<<" ";
          
        int cnt=0;
        
        for(int i=0;i<experience.size();i++){
            if(experience[i]>=initialExperience){
                int temp=experience[i]-initialExperience+1;
                cnt+=temp;
                initialExperience+=temp+experience[i];
            }
            else  initialExperience+=experience[i];
            
        }
        return ans+cnt;
      
    }
};