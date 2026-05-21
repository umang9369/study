class Solution {
private:
    int atmost(vector<int>& nums, int k){
        if(k<0)return 0;
        int l=0;
        int r=0;
        int count=0;
        int sum=0;
        int n=nums.size();
        while(r<n){
            sum += nums[r]%2;
            while(sum>k){
                sum -=nums[l]%2; //window shrink
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};
