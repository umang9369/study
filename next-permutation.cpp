class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int gola_index = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                gola_index = i - 1;
                break;
            }
        }
        if (gola_index != -1) {
            for (int j = n - 1; j > gola_index; j--) {
                if (nums[j] > nums[gola_index]) {
                    swap(nums[j], nums[gola_index]);
                    break;
                }
            }
        }
        reverse(nums.begin() + gola_index + 1, nums.end());
    }
};
//main function likh do
