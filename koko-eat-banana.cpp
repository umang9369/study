class Solution {
public:
    bool caneat(vector<int>& piles, int h,int mid){
        int hours=0;
        for(int &x : piles){
            hours += x/mid;
            if(x % mid != 0){
            hours++;
        }
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(begin(piles),end(piles));
        while(low<high){
            int mid=low+(high-low)/2;
            if(caneat(piles,h,mid)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
