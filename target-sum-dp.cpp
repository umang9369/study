class Solution {
public:
    int n,s;
    int solve(vector<int>& nums, int target,int i,int curr,vector<vector<int>>&t){
        if(i==n)return (curr==target)?1:0;
        if(t[i][curr+s]!=-1){
            return t[i][curr+s];
        }
        int plus=solve(nums,target,i+1,curr+nums[i],t);
        int minus=solve(nums,target,i+1,curr-nums[i],t);
        return t[i][curr+s]=plus+minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        s=accumulate(begin(nums),end(nums),0);
        vector<vector<int>>t(n+1,vector<int>(2*s+1,-1));
        return solve(nums,target,0,0,t);
    }
};
