class Solution {
public:
    int t[201][20001];
    bool solve(vector<int>& nums,int i,int x){
        if(x==0)return true;
        if(i>=nums.size())return false;
        bool take =false;
        if(t[i][x]!=-1){
            return t[i][x];
        }
        if(nums[i]<=x){
            take=solve(nums,i+1,x-nums[i]);
        }
        bool nottake=solve(nums,i+1,x);
        return t[i][x]=take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(begin(nums),end(nums),0);
        memset(t,-1,sizeof(t));
        if(sum%2!=0)return false;
        int x=sum/2;
        return solve(nums,0,x);
    }
};
