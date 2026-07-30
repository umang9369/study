class Solution {
public:
    bool bfs(int src, vector<vector<int>>& adj, vector<bool>& vis) {

        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = true;

        while(!q.empty()) {

            auto [node,parent] = q.front();
            q.pop();

            for(int neigh : adj[node]) {
   
                if(!vis[neigh]) {
                    vis[neigh] = true;
                    q.push({neigh,node});
                }
                else if(neigh != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        // Convert edge list to adjacency list
        vector<vector<int>> adj(V);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(V,false);

        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(bfs(i,adj,vis))
                    return true;
            }
        }

        return false;
    }
};
