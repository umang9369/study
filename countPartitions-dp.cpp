class Solution {
  public:
    int t[51][10001];
    int solve(int n,int sum,vector<int>& arr){
        if(n==0){
            return (sum==0)?1:0;
        }
        if(t[n][sum]!=-1){
            return t[n][sum];
        }
        int skip=solve(n-1,sum,arr);
        int take=0;
        if(arr[n-1]<=sum){
            take=solve(n-1,sum-arr[n-1],arr);
        }
        return t[n][sum]=(take+skip);
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n=arr.size();
        int s=accumulate(begin(arr),end(arr),0);
        if((s+diff)%2!=0){
            return 0;
        }
        int target=(s+diff)/2;
        memset(t,-1,sizeof(t));
        return solve(n,target,arr);
    }
};
