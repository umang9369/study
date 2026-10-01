class Solution {
  public:
    int n;
    int t[1001][1001];
    int solve(int n,int W,vector<int> &val, vector<int> &wt){
        if (n==0 || W==0)return 0;
        if(t[n][W]!=-1){
            return t[n][W];
        }
        int take=0;
        if(wt[n-1]<=W){
            take=val[n-1]+solve(n-1,W-wt[n-1],val,wt);
        }
        int skip=solve(n-1,W,val,wt);
        return t[n][W]= max(take,skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        n=val.size();
        memset(t,-1,sizeof(t));
        return solve(n,W,val,wt);
    }
};
