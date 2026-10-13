class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        int i=0;
        int j=nums.size()-1;
        long long ans=0;
        while(i<=j){
            ans+=1LL*nums[j]*nums[j];
            if(i!=j){
                ans-=1LL*nums[i]*nums[i];
            }
            i++;
            j--;
        }
        return ans;
    }
};
