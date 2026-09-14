class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans=0;
        for (int i = 2; i < (int)stones.size(); ++i) {
            ans = max(ans, stones[i] - stones[i - 2]);
        }
        return ans;
    }
};
