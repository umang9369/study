class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        sort(begin(arr),end(arr));
        sort(begin(dep),end(dep));
        int count=0;
        int maxi=0;
        int i=0;
        int j=0;
        while(i<n){
            if(arr[i]<=dep[j]){
                count++;
                maxi=max(maxi,count);
                i++;
            }else{
                count--;
                j++;
            }
        }
        return maxi;
    }
};
