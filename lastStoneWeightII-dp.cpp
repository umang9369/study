class Solution {
public:
    int n,sum,tar,ans;
    int t[31][3001];
    int solve(vector<int>& stones,int i,int curr){
        if(i>=n)return t[i][curr]=curr;
        if(t[i][curr] !=-1){return t[i][curr];}
        int take=solve(stones,i+1,curr+stones[i]);
        int skip=solve(stones,i+1,curr);
        if(abs(sum/2-take)<abs(sum/2-skip)){
            return t[i][curr]=take;
        }else{
            return t[i][curr]=skip;
        }
    }
    int lastStoneWeightII(vector<int>& stones) {
        n=stones.size();
        sum=accumulate(stones.begin(),stones.end(),0);
        tar=ceil(sum/2);
        memset(t,-1,sizeof(t));
        ans=solve(stones,0,0);
        return abs(sum-2*ans);
    }
};
