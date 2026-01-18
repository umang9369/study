class Solution {
public:
    bool ispalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    void solve(string s, vector<vector<string>>& ans, vector<string>& partitions) {
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);

            if (ispalindrome(part)) {
                partitions.push_back(part);
                solve(s.substr(i + 1), ans, partitions);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        solve(s, ans, partitions);
        return ans;
    }
};
