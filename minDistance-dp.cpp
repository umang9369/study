class Solution {
public:
    int m,n;
    int t[501][501];
    int solve(string &s1, string &s2,int i,int j){
        if(i==m)return n-j;
        if(j==n)return m-i;
        if(t[i][j]!=-1)return t[i][j];
        if(s1[i]==s2[j]){
            return t[i][j]=solve(s1,s2,i+1,j+1);
        }else{
            int insertion=1+solve(s1,s2,i,j+1);
            int del=1+solve(s1,s2,i+1,j);
            int replace=1+solve(s1,s2,i+1,j+1);
            return t[i][j]=min({insertion,del,replace});
        }
        return -1;
    }
    int minDistance(string s1, string s2) {
        m=s1.size();
        n=s2.size();
        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);
    }
};
