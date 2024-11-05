class Edge{
public:    
    int node;
    int weight;
    Edge(int n ,int w){
        this->node=n;
        this->weight=w;
    }

};
class Solution {
    int n;
    const int INF=1e9;
    vector<vector<Edge>>adj;
    vector<int> dijkstra(int src){
        vector<int> d(n+1 ,INF);
        d[src]=0;
        vector<bool>mark(n+1 ,false);
        for(int i=0 ; i<n ; i++){
            int dmin=INF ,curr=-1;
            for(int j=1;j<=n;j++){
                if(mark[j]==false && dmin>=d[j]){
                    dmin=d[j];
                    curr=j;
                }
            }
            if(curr==-1)break;
            mark[curr]=true;
            for(auto& e:adj[curr]){
                int v=e.node;
                int w=e.weight;
                d[v]=min(d[v],d[curr]+w);
            }
            
        }
        for(int& val :d){
            if(val==INF){
                val=-1;
            }
        }
        return d;
    }

    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        this->n=n;
        adj.resize(n+1);
        for(auto& t:times){
            int u=t[0];
            int v=t[1];
            int w=t[2];
            Edge ed(v,w);
            adj[u].push_back(ed);
        }
        vector<int> d=dijkstra(k);
        int t=-1;
        for(int i=1;i<=n;i++){
            if(d[i]==-1)return -1;
            t=max(t,d[i]);
        }
        return t;

    }
};