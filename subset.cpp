#include <vector>
using namespace std;

class Solution {
private:
    void solve(int index, vector<int>& output,
               vector<vector<int>>& ans, vector<int>& nums) {

        if (index == nums.size()) {
            ans.push_back(output);
            return;
        }

        // Include 
        output.push_back(nums[index]);
        solve(index + 1, output, ans, nums);
        // Exclude 
        output.pop_back();
        solve(index + 1, output, ans, nums);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;

        solve(0, output, ans, nums);
        return ans;
    }
};