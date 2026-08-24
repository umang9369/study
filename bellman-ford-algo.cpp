class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>res(V,1e8);
        res[src]=0;
        for(int i=1;i<=V-1;i++){
            for(auto &edge:edges){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                if(res[u]!=1e8 && res[u]+w<res[v]){
                    res[v]=res[u]+w;
                }
            }
        }
        for(auto &edge:edges){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                if(res[u]!=1e8 && res[u]+w<res[v]){
                    return {-1};
                }
            }
        return res;
    }
};
