class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                    ans=max(ans,t[i][j]);
                }else{
                    t[i][j]=0;
                }
            }
        }
        return ans;
    }
};
