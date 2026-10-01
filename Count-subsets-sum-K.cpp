class Solution {
  public:
    int t[1001][1001];
    int solve(int n,int target,vector<int>& arr){
        if(n==0)return (target==0)?1:0;
        if(t[n][target]!=-1){
            return t[n][target];
        }
        int skip=solve(n-1,target,arr);
        int take=0;
        if(arr[n-1]<=target){
            take=solve(n-1,target-arr[n-1],arr);
        }
        return t[n][target]=take+skip;
    }
    int perfectSum(vector<int>& arr, int target){
        int n=arr.size();
        memset(t,-1,sizeof(t));
        return solve(n,target,arr);
    }
};
