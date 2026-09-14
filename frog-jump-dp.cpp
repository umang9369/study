class Solution {
public:
    int n;
    unordered_map<int,int>mp;
    int t[2001][2001];
    bool solve(vector<int>& stones,int csi,int pj){
        if(csi==n-1)return true;
        bool res=false;
        if(t[csi][pj] != -1)return t[csi][pj];
        for(int nextjump=pj-1;nextjump<=pj+1;nextjump++){
            if(nextjump>0){
                int nxtstone=stones[csi]+nextjump;
                if(mp.find(nxtstone)!=mp.end()){
                    res=res || solve(stones,mp[nxtstone],nextjump);
                }
            }
        }
        return t[csi][pj]=res;
    };
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)return false;
        n=stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        memset(t,-1,sizeof(t));
        return solve(stones,0,0);
    }
};
