class Solution {
public:
    int solve(int i,int op,int k ,vector<int>& prices,vector<vector<int>>&dp){
        if(i==prices.size()||op==2*k)return 0;
        int profit=0;
        if(dp[i][op]!=-1)return dp[i][op];
        if(op%2==0){
            int buykaro=-prices[i]+solve(i+1,op+1,k,prices,dp);
            int skipkaro=0+solve(i+1,op,k,prices,dp);
            profit=max(buykaro,skipkaro);
        }else{
            int sellkaro=prices[i]+solve(i+1,op+1,k,prices,dp);
            int skipkaro=0+solve(i+1,op,k,prices,dp);
            profit=max(sellkaro,skipkaro);
        }
        return dp[i][op]=profit;
    }
    int maxProfit(int k, vector<int>& prices){
        vector<vector<int>>dp(prices.size(),vector<int>(2*k,-1));
        return solve(0,0,k,prices,dp);
    }
};
