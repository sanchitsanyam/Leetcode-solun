class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i;
        for(i=0; i<heights.size()-1 ; i++){
            int diff=heights[i+1]-heights[i];
            if(diff>0){
                if(bricks>=diff){
                    bricks-=diff;
                    pq.push(diff);
                }
                else if(ladders>0){
                    if(!pq.empty()&& pq.top()>diff){
                        bricks+=pq.top()-diff;
                        pq.pop();
                        pq.push(diff);
                        ladders--;
                    }
                    else{
                        ladders--;
                    }
                }
                else{
                    break;
                }
            }    
        }
        return i;
        
    }
};