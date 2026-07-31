class Solution {
public:
    void dfs(vector<vector<char>>& grid,int u,int v){
        int n=grid.size();
        int m=grid[0].size();
        if(grid[u][v]!='O')return;
        grid[u][v]='Z';
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=u+drow[i];
            int ncol=v+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                dfs(grid,nrow,ncol);
            }
        }
    }
//we can also use bfs to traverse

    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    dfs(grid,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='Z'){
                    grid[i][j]='O';
                }else if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
    }
};
