class Solution {
public:
    int m,n;
    const int mod=1e9+7;
    int t[501][501][3];
    int solve(vector<vector<int>>& grid,int i,int j ,int d){
        if(i==m-1 && j==n-1)return 1;
        if(i>=m || j>=n)return 0;
        if(t[i][j][d]!=-1)return t[i][j][d];
        if(grid[i][j]==1){
            if(d==0){
                return t[i][j][d]=solve(grid,i+1,j,1);
            }else{
                return t[i][j][d]=solve(grid,i,j+1,0);
            }
        }
        return t[i][j][d]=(solve(grid,i+1,j,1)+solve(grid,i,j+1,0))%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(grid,0,0,0);
    }
};
