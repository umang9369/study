class Solution {
public:
    int m,n;
    bool dfs(vector<vector<int>>& grid,int i,int j){
        if(i>=m || i<0 || j>=n || j<0)return false;
        if(grid[i][j]==1)return true;
        grid[i][j]=1;
        bool left=dfs(grid,i,j-1);
        bool right=dfs(grid,i,j+1);
        bool up=dfs(grid,i-1,j);
        bool down=dfs(grid,i+1,j);
        return left&&right&&up&&down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
