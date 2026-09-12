class Solution {
  public:
    vector<int>dt,low;
    int time;
    void dfs(int u,int paru,vector<vector<int>>& adj,set<int>&cc){
        int child=0;
        dt[u]=low[u]=++time;
        for(auto v:adj[u]){
            if(dt[v]==-1){
                child++;
                dfs(v,u,adj,cc);
                low[u]=min(low[u],low[v]);
                if(paru!=-1 && low[v]>=dt[u]){
                    cc.insert(u);
                }
            }else if(v !=paru){
                low[u]=min(low[u],dt[v]);
            }
        }
        if(paru ==-1 && child>1){
            cc.insert(u);
        }
    }
    vector<int> articulationPoints(int n, vector<vector<int>>& grid) {
        vector<vector<int>> adj(n);
        for(auto edge : grid){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        time=0;
        dt.assign(n,-1);
        low.assign(n,0);
        set<int>cc;
        for(int i=0;i<n;i++){
            if(dt[i]==-1){
                dfs(i,-1,adj,cc);
            }
        }
        if(cc.empty()){
            return {-1};
        }
        return vector<int>(cc.begin(), cc.end());
    }
};
