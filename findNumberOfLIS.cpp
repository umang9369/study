class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n,1),cnt(n,1);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    if(t[i]==t[j]+1){
                        cnt[i]+=cnt[j];
                    }else if(t[i]<t[j]+1){
                        t[i]=t[j]+1;
                        cnt[i]=cnt[j];
                    }
                }
            }
        }
        int maxi=*max_element(begin(t),end(t));
        int res=0;
        for(int i=0;i<n;++i){
            if(t[i]==maxi){
                res+=cnt[i];
            }
        }
        return res;
    }
};
