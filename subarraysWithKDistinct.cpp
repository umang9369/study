class Solution {
private:
    int answer(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int n=nums.size();
        int count=0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return answer(nums,k)-answer(nums,k-1);
    }
};
