class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>>adj(V);
        for (auto &edge:edges) {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>res(V,INT_MAX);
        res[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (d>res[node])continue;
            for(auto &it : adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(d+wt<res[adjnode]){
                    res[adjnode]=d+wt;
                    pq.push({d+wt,adjnode});
                }
            }
        }
        return res;
    }
};
