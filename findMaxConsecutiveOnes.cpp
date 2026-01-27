class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int ctmax = INT_MIN;
        for(int i=0; i<n;i++){
            if(nums[i]==1){
                count++;
            }
            else{
                ctmax = max(ctmax,count);
                count = 0;
            }
        }
        ctmax=max(ctmax,count);
        return ctmax;
    }
};
