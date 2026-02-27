class Solution {
  public:
    bool ispossible(vector<int> &stalls,int k ,int mid){
        int cows=1;
        int laststall=stalls[0];
        for(int i=0;i<stalls.size();i++){
            if(stalls[i]-laststall>= mid){
                cows++;
                laststall=stalls[i];
            }
            if(cows >= k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int low =1;
        int high=* max_element(begin(stalls),end(stalls)) - *min_element(begin(stalls),end(stalls));
        int ans=-1;
        sort(stalls.begin(),stalls.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(stalls,k,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};
//main 
