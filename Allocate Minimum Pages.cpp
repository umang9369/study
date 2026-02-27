class Solution {
  public:
    int func(vector<int> &arr, int pages){
        int stud=1;
        int pageallocated = 0;
        for(int i=0;i<arr.size();i++){
            if( pageallocated+arr[i] <= pages){
                pageallocated +=arr[i];
            }else{
                stud+=1;;
                pageallocated=arr[i];
            }
        }
        return stud;
    }
    int findPages(vector<int> &arr, int k) {
        int low=*max_element(begin(arr),end(arr));
        int high = accumulate(begin(arr),end(arr),0);
        if(k > arr.size()) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int students=func(arr,mid);
            if(students > k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};
