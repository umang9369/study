class Solution {
public:
    int n;
    int dp[301];
    unordered_set<string> st;
    bool solve(int idx, string &s) {
        if (idx >= n) {
            return true;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        for (int l = 1; l <= n-idx; l++) {   
            string temp = s.substr(idx, l);
            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        for (string &word : wordDict) {
            st.insert(word);
        }
        return solve(0, s); 
    }
};
//main functio write on your own
