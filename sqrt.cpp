class Solution {
public:
    int mySqrt(int x) {
        if(x<2)return x;
        long long l=1;
        long long r =x/2;
        int ans;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(mid*mid<=x){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};
