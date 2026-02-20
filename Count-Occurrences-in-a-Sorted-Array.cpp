class Solution {
  public:
    int findleft(vector<int>& nums, int target,int n){
        n=nums.size();
        int low=0;int high=nums.size()-1;
        int leftmost=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                leftmost=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return leftmost;
    };
    int findright(vector<int>& nums, int target,int n){
        n=nums.size();
        int low=0;int high=nums.size()-1;
        int rightmost=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                rightmost=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return rightmost;
    };
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=findleft(nums,target,nums.size());
        int right=findright(nums,target,nums.size());
        return {left, right};
    }
    int countFreq(vector<int>& nums, int target) {
        vector<int> ans = searchRange(nums, target);
        if(ans[0]==-1)return 0;
        return ans[1] - ans[0] + 1;;
    }
};
