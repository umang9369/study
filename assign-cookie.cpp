class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int i=0;
        int j=0;
        int m=g.size();
        int n=s.size();
        while(i<m && j<n){
            if(g[i]<=s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};
