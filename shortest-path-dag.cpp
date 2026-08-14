class Solution {
  public:
    void topo(int node,int vis[],stack<int>&st,vector<pair<int,int>>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                topo(it.first,vis,st,adj);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[V];
        int m=edges.size();
        int src=0;
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        int vis[V]={0};
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topo(i,vis,st,adj);
            }
        }
        vector<int>dist(V,1e9);
        dist[src]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(dist[node != 1e9]){
                for(auto it : adj[node]){
                    if(dist[node]+it.second<dist[it.first]){
                        dist[it.first]=dist[node]+it.second;
                    }
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
