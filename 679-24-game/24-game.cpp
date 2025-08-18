class Solution {
public:
    bool help(vector<double>& c){
        if(c.size()==1){
            if(fabs(c[0]-24.0)<=1e-6){
                return true;
            }
            else return false;
        }
        else{
            for(int i=0;i<c.size();i++){
                for(int j=0;j<c.size();j++){
                    if(i==j)continue;
                    vector<double> next;
                    for(int k=0;k<c.size();k++){
                        if(i!=k && j!=k)next.push_back(c[k]);
                    }
                    double a=c[i],b=c[j];
                    vector<double> result={a*b,a-b,b-a,a+b};
                    if(fabs(a)>1e-6)result.push_back(b/a);
                    if(fabs(b)>1e-6)result.push_back(a/b);
                    for(auto& r:result){
                        next.push_back(r);
                        if(help(next))return true;
                        next.pop_back();
                    }
                }
            }
            return false;
        }
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> c(cards.begin(),cards.end());
        return help(c);
    }
};