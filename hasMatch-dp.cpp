class Solution {
public:
    int m,n;
    int t[51][51];
    bool solve(string &s, string &p,int i,int j){
        if (j == p.size()) return true;
        if (i == s.size()) {
            for (int k = j; k < p.size(); k++)
                if (p[k] != '*') return false;
            return true;
        }
        if(t[i][j]!=-1)return t[i][j];
        if(p[j]=='*'){
            return t[i][j]=(solve(s,p,i+1,j)||solve(s,p,i,j+1));
        }
        if(s[i]==p[j]){
            return t[i][j]=solve(s,p,i+1,j+1);
        }
        return t[i][j]=false;
    }
    bool hasMatch(string s, string p) {
        m=s.size();
        n=p.size();
        memset(t,-1,sizeof(t));
        for (int i = 0; i <= m; i++) {
            if (solve(s,p,i,0))
                return true;
        }
        return false;
    }
};
