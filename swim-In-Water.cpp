class Solution {
public:
    vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    int n;
    bool solve(vector<vector<int>>& grid,int l,int r,int mid,vector<vector<bool>>&vis){
        if(l<0 || l>=n || r<0 || r>=n || vis[l][r]==true || grid[l][r]>mid){
            return false;
        }
        vis[l][r]=true;
        if(l==n-1 && r==n-1){
            return true;
        }
        for(auto &d:dir){
            int i=l+d[0];
            int j=r+d[1];
            if(solve(grid,i,j,mid,vis)){
                return true;
            }
        }
        return false;
    };
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        int l=grid[0][0];
        int r=n*n-1;
        int res=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            vector<vector<bool>>vis(n,vector<bool>(n,false));
            if(solve(grid,0,0,mid,vis)){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};
