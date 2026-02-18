class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        int ans=arr.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<target){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};
