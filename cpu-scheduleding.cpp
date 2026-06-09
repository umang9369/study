class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        long long n=bt.size();
        long long wttime=0;
        long long t=0;
        for(int i=0;i<n;i++){
            wttime+=t;
            t+=bt[i];
        }
        return (wttime/bt.size());
    }
};
