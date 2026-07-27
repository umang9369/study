class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isConnected,int u,vector<bool>& visited){
        visited[u]=true;
        for(int v=0;v<n;v++){
            if(!visited[v] && isConnected[u][v]==1 ){
                dfs(isConnected,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(isConnected,i,visited);
            }
        }
        return count;
    }
};
