class Solution {
public:
    void dfs(vector<vector<int>>& grid,int u,int v){
        int m=grid.size();
        int n=grid[0].size();
        if(u>=m || u<0 || v>=n || v<0 || grid[u][v]==0)return;
        grid[u][v]=0;
        dfs(grid,u+1,v);
        dfs(grid,u,v+1);
        dfs(grid,u-1,v);
        dfs(grid,u,v-1);
    }
//bfs can also be used here
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    dfs(grid,i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};
