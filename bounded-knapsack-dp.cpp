class Solution {
  public:
    long long solve(int i,vector<int>& val, vector<int>& wt, int W,vector<vector<long long>>&dp){
        if(i==0)return (long long)(W/wt[0])*val[0];
        if(dp[i][W]!=-1)return dp[i][W];
        long long skip=0+solve(i-1,val,wt,W,dp);
        long long take=0;
        if(wt[i]<=W){
            take=val[i]+solve(i,val,wt,W-wt[i],dp);
        }
        return dp[i][W]=max(take,skip);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        int n=val.size();
        vector<vector<long long>> dp(n, vector<long long>(W + 1, -1));
        return (int)solve(n-1,val,wt,W,dp);
    }
};
