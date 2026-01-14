class Solution {
public:
    void solve(vector<int>& candidates, int target, int idx,
               vector<int>& curr, vector<vector<int>>& result) {

        if (target < 0)
            return;

        if (target == 0) {
            result.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            curr.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, curr, result);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, curr, result);

        return result;
    }
};
