class Solution {
  public:
    int func(long long mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= mid;
            if (ans > m) return 1;   
        }
        if (ans == m) return 0;      
        return -1;                  
    }
    int nthRoot(int n, int m) {
        if (m == 0) return 0;   
        long long low = 1;
        long long high = m;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int val = func(mid, n, m);
            if (val == 0) {
                return mid;
            } else if (val == -1) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
//main
