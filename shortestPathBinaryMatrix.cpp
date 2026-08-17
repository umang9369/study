class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1)return -1;
        int dir[][2]={{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,1},{-1,-1},{1,1}};
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vis[0][0]=true;
        queue<vector<int>>q;
        q.push({0,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto curr=q.front();
                q.pop();
                if(curr[0]==m-1 && curr[1]==n-1){
                    return ans+1;
                }
                for(int k=0;k<8;k++){
                    int newx=dir[k][0]+curr[0];
                    int newy=dir[k][1]+curr[1];
                    if(newx>=0 && newx<m && newy>=0 && newy<n && !vis[newx][newy] && grid[newx][newy]==0){
                        q.push({newx,newy});
                        vis[newx][newy]=true;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
