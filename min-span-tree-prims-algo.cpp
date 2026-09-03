class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V);
        for(auto it : edges) {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int ewt=it.second;
                if(!vis[adjnode]){
                    pq.push({ewt,adjnode});
                }
            }
        }
        return sum;
    }
};
