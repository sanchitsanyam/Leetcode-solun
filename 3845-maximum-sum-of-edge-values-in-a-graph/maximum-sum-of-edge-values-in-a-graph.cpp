class Solution {
public:
    using ll = long long;
    vector<bool> v;
    bool dfs(int i,int p ,vector<vector<int>>& adj, int& cnt ,int a){
        v[i]=true;
        cnt++;
        for( auto& u : adj[i]){
            if(!v[u]){
                if(dfs(u,i,adj,cnt,u))return true;
            }
            else if(u!=p)return true;
        }
        return false;

    }
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        v=vector<bool>(n+1,false);
        vector<pair<int,int>> c,nc;// cyclic and non-cyclic size -{cnt ,start node};
        for(int i=0;i<n;i++){
            if(!v[i]){
                int cnt=0;
                if(dfs(i,-1,adj,cnt,i)){
                    c.push_back({cnt,i});
                }
                else{
                    nc.push_back({cnt,i});
                }
            }
        }
        sort(c.rbegin(),c.rend());
        sort(nc.rbegin(),nc.rend());
        ll ans=0;
        v= vector<bool>(n+1,false);
        int val =n;
        for(auto& i :c){
            int s=i.first;
            vector<ll> a(s);
            int st=val-s+1,e=val;
            int j=0;
            for(j=0; j < s/2;j++){
                a[j]=st++,a[s-j-1]=st++;
            }
            if(s%2)a[j]=st;
            for(int i=1;i<s;i++){
                ans+= (ll (a[i-1])*ll(a[i]));
            }
            ans+=a.back()*a.front();
            val=val-s;
        }
        for(auto& i : nc){
            int s=i.first;
            vector<ll> a(s);
            int st=val-s+1,e=val;
            int j=0;
            for(j=0; j < s/2;j++){
                a[j]=st++,a[s-j-1]=st++;
            }
            if(s%2)a[j]=st;
            for(int i=1;i<s;i++){
                ans+= (ll (a[i-1])*ll(a[i]));
            }
            val=val-s;
        }
        return ans;
    }
};