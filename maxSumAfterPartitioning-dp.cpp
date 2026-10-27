class Solution {
public:
    int n;
    int t[501];
    int solve(vector<int>& arr,int i,int k){
        if(i>=n)return 0;
        int sum=0;
        int curr=0;
        if(t[i]!=-1)return t[i];
        for(int j=i;j<n && j-i+1<=k;++j){
            curr=max(curr,arr[j]);
            int temp=((j-i+1)*curr)+solve(arr,j+1,k);
            sum=max(sum,temp);
        }
        return t[i]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        memset(t,-1,sizeof(t));
        return solve(arr,0,k);
    }
};
