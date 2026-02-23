class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low=0;
        int high=arr.size()-1;
        int ans=INT_MAX,min_ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[low]<=arr[mid]){
                if(arr[low]<ans){
                    min_ans=arr[low];
                    min_ans=low;
                }
                ans=min(ans,arr[low]);
                low=mid+1;
            }else{
                if(arr[mid]<ans){
                    min_ans=arr[mid];
                    min_ans=mid;
                }
                high=mid-1;
                ans=min(ans,arr[mid]);
            }
        }
        return min_ans;
    }
};

