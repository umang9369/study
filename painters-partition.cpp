class Solution {
  public:
    int func(vector<int>& arr, int mid ){
        int painters = 1;
        int boardsPainter=0;
        for(int i=0;i<arr.size();i++){
            if(boardsPainter+arr[i] <= mid){
                boardsPainter+=arr[i];
            }else{
                painters++;
                boardsPainter=arr[i];
            }
        }
        return painters;
    }
    int minTime(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        if(k > arr.size()) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int painters=func(arr,mid);
            if(painters > k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};
