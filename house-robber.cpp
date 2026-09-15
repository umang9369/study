class Solution {
public:
    int t[101];
    int solve(vector<int>& nums,int i,int c){
        if(i>c)return 0;
        if(t[i]!=-1)return t[i];
        int take=nums[i]+solve(nums,i+2,c);
        int skip=solve(nums,i+1,c);
        return t[i]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        memset(t,-1,sizeof(t));
        int a = solve(nums, 0, n-2);
        memset(t,-1,sizeof(t));
        int b = solve(nums, 1, n-1);
        return max(a,b);
    }
};
