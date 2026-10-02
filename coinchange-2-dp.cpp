class Solution {
public:
    int n;
    int t[301][10001];
    int solve(int n, int amt, vector<int>& coins) {
        if (n == 0)
            return (amt == 0) ? 1 : 0;
        if(amt<coins[n-1])return solve(n-1,amt,coins);

        if (t[n][amt] != -1) {
            return t[n][amt];
        }

        int skip = solve(n - 1, amt, coins);

        int take = 0;
        if (coins[n - 1] <= amt) {
            take = solve(n, amt - coins[n - 1], coins);
        }

        return t[n][amt] = (take + skip);
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t, -1, sizeof(t));
        return solve(n, amount, coins);
    }
};

