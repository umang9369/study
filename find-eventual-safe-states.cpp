class Solution {
public:
    bool dfs(int src,vector<int>&vis,vector<int>&recpath,vector<vector<int>>& graph){
        vis[src]=true;
        recpath[src]=true;
        for(int &v:graph[src]){
            if(vis[v]==false && dfs(v,vis,recpath,graph)){
                return true;
            }
            else if(recpath[v]){
                return true;
            }
        }
        recpath[src]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,false);
        vector<int>recpath(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,recpath,graph);
            }
        }
        vector<int>safenode;
        for(int i=0;i<n;i++){
            if(!recpath[i]){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};
