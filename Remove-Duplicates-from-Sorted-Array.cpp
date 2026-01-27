class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int key = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] != nums[i]){
                nums[key] = nums[i];
                key++;
            }
        }
        return key;
    }
};
