class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int> &vec: flights){
            int u=vec[0];
            int v=vec[1];
            int cost=vec[2];
            adj[u].push_back({v,cost});
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src]=0;
        int step=0;
        while(!q.empty() && step<=k){
            int N=q.size();
            while(N--){
                int u=q.front().first;
                int d=q.front().second;
                q.pop();
                for(pair<int,int>&P:adj[u]){
                    int v=P.first;
                    int cost=P.second;
                    if(dist[v]>d+cost){
                        dist[v]=d+cost;
                        q.push({v,d+cost});
                    }
                }
            }
            step++;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
