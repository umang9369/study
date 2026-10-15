class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int count=0;
        int ans=0;
        for(int i=0;i<nums.size();++i){
            set<int>s;
            for(int j=i;j<nums.size();++j){
                s.insert(nums[j]);
                count=s.size();
                ans += count*count;
            }
        }
        return ans;
    }
};
