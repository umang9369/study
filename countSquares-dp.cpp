class Solution {
public:
    int m,n;
    int t[301][301];
    int solve(int i,int j,vector<vector<int>>& matrix){
        if(i>=m || j>=n || matrix[i][j]==0)return 0;
        if(t[i][j]!=-1)return t[i][j];
        int right=solve(i,j+1,matrix);
        int daigonal=solve(i+1,j+1,matrix);
        int down=solve(i+1,j,matrix);
        return t[i][j]=1+min({right,daigonal,down});
    }
    int countSquares(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        memset(t,-1,sizeof(t));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    ans +=solve(i,j,matrix);
                }
            }
        }
        return ans;
    }
};
