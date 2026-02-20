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
        int left_most=findleft(nums,target,nums.size());
        int right_most=findright(nums,target,nums.size());
        return {left_most, right_most};
    }
};
