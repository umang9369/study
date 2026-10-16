class Solution {
public:
    int t[1001][1001];
    int solve(string &s1,string &s2,int m,int n){
        if(m==0 || n==0)return t[m][n]=0;
        if(t[m][n]!=-1)return t[m][n];
        if(s1[m-1]==s2[n-1])return t[m][n]=1+solve(s1,s2,m-1,n-1);
        return t[m][n]=max(solve(s1,s2,m-1,n),solve(s1,s2,m,n-1));
    }
    int longestPalindromeSubseq(string s1) {
        int m=s1.size();
        memset(t,-1,sizeof(t));
        string s2=s1;
        reverse(begin(s2),end(s2));
        return solve(s1,s2,m,m);
    }
};
