class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0;
        int res=0;
        unordered_map<char,int> mp={{'a',0},{'b',0},{'c',0}};
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                res += n-r;
                mp[s[l]]--;
                l++;
            }
        }
        return res;
    }
};
//main
