class Solution {
public:
    void solve(int i, vector<int>& arr, int target,
               vector<int>& combin, vector<vector<int>>& ans) {
        
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        if (i == arr.size() || target < 0) {
            return;
        }

        // Pick the current element
        combin.push_back(arr[i]);
        solve(i, arr, target - arr[i], combin, ans);
        combin.pop_back();

        // Skip the current element
        solve(i + 1, arr, target, combin, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        solve(0, arr, target, combin, ans);
        return ans;
    }
};

//use main function accordingly 