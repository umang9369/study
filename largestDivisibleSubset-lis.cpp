class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>t(n,1);
        vector<int>previndex(n,-1);
        int lastindex=0;
        int maxi=1;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0){
                    if(t[i]<t[j]+1){
                        t[i]=t[j]+1;
                        previndex[i]=j;
                    }
                    if(t[i]>maxi){
                        maxi=t[i];
                        lastindex=i;
                    }
                }
            }
        }
        vector<int>res;
        while(lastindex !=-1){
            res.push_back(nums[lastindex]);
            lastindex=previndex[lastindex];
        }
        return res;
    }
};
