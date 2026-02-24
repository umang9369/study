class Solution {
  public:
    int floorSqrt(int n) {
        int low=1;
        int high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if((mid*mid)<=n){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return high;
    }
};
