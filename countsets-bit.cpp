class Solution {
  public:
    int countSetBits(int n) {
        int res=0;
        for(int i=0;i<n+1;i++){
            res +=__builtin_popcount(i);
        }
        return res;
    }
};
