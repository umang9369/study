class Solution {
  public:
    int getSecondLargest(vector<int> &nums) {
        int largest = nums[0];
        int slargest = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > largest) {
                largest = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > slargest && nums[i] != largest) {
                slargest = nums[i];
            }
        }
        return slargest;
    }
};
//mian function khud bnao
