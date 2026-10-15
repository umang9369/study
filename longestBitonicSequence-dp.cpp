class Solution {
  public:
    int C(int n, vector<int> &nums) {
        vector<int>lis(n,1),lds(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[i],1+lis[j]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    lds[i]=max(lds[i],1+lds[j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if (lis[i] != 1 && lds[i] != 1) {
                ans = max(ans,lis[i]+lds[i]-1);
            }
        }
        return ans;
    }
};
