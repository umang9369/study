class Solution {
public:
    int sum(vector<int>& nums, int divisor){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double)(nums[i])/(double)(divisor));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high= *max_element(begin(nums),end(nums));
        while(low<=high){
            int mid=low+(high-low)/2;
            if(sum(nums,mid) <= threshold){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
