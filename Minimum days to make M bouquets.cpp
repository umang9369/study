class Solution {
public:
    int bouquet(vector<int>& bloomDay, int m, int k , int mid){
        int bouquet_count = 0;
        int cons_count = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid ){
                cons_count++;
            }else{
                cons_count=0;
            }
            if(cons_count == k){
                bouquet_count++;
                cons_count=0;
            }
        }
        return bouquet_count;
    };
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int minDays=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(bouquet(bloomDay,m,k,mid) >= m ){
                minDays=mid;
                end = mid-1;
            }else{
                start=mid+1;
            }
        }
        return minDays;
    }
};
