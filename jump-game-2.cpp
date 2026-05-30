class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int jump=0;
        int n=nums.size();
        //min farthest use krke usme l ko r ke ek aage aur r ko farthest bna kr krenge
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(i+nums[i],farthest);
            }
            jump++;
            l=r+1;
            r=farthest;
        }
        return jump;
    }
};
