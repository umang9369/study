class Solution {
public:
    const long long MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>count(32,0);
        for(auto num:nums){
            for(int b=0;b<32;++b){
                if(num & (1LL<<b)){
                    count[b]++;
                }
            }
        }
        long long res=0;
        while(k--){
            long long curr=0;
            for(int b=0;b<32;++b){
                if(count[b]>0){
                    count[b]--;
                    curr |= (1LL << b); 
                }
            }
            res=(res+1LL*curr*curr)%MOD;
        }
        return res;
    }
};
