class Solution {
public:
    int t[103][103];
    int solve(vector<int>& cuts,int l,int r){
        if((r-l)<2)return 0;
        if(t[l][r]!=-1)return t[l][r];
        int res=INT_MAX;//-infintiy lenge
        for(int i=l+1;i<=r-1;++i){
            int cost=(cuts[r]-cuts[l])+solve(cuts,l,i)+solve(cuts,i,r);
            res=min(res,cost);
        }
        return t[l][r]=res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts),end(cuts));
        memset(t,-1,sizeof(t));
        cuts.insert(begin(cuts),0);
        cuts.push_back(n);
        return solve(cuts,0,cuts.size()-1);
    }
};
