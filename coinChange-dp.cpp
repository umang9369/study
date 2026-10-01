class Solution {
public:
    int n;
    int t[13][10001];
    int solve(int n,int amt,vector<int>& coins) {
        if(amt==0)return 0;
        if(n==0)return 1e9;
        if(t[n][amt]!=-1)return t[n][amt];
        int skip=solve(n-1,amt,coins);
        int take=1e9;
        if(coins[n-1]<=amt) {
            take=1+solve(n,amt-coins[n-1],coins);
        }
        return t[n][amt]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        memset(t,-1,sizeof(t));
        int ans=solve(n,amount,coins);
        return(ans>=1e9)?-1:ans;
    }
};
