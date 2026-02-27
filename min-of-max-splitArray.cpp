class Solution {
  public:
    int func(vector<int>& arr, int mid){
        int partitions=1;
        int subarraysum=0;
        for(int i=0;i<arr.size();i++){
            if(subarraysum+arr[i] <= mid){
                subarraysum += arr[i];
            }else{
                partitions++;
                subarraysum=arr[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& arr, int k) {
        int low=*max_element(arr.begin(),arr.end());
        int high= accumulate(arr.begin(),arr.end(),0);
        
        while(low<=high){
            int mid = low+(high-low)/2;
            int sum=func(arr,mid);
            if(sum > k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};
