class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int count=0;
        long xr=0;
        unordered_map<int,int> fmap;
        fmap[0] = 1;
        for(int i=0;i<arr.size();i++){
            xr ^= arr[i];
            if (fmap.find(xr^k) != fmap.end()) {
                count += fmap[xr^k];
            }
            fmap[xr]++;
        }
        return count;
    }
};
//main functin on your own
