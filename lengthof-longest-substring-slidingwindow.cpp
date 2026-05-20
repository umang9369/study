class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int n=s.size();
        int l=0;
        int r=0;
        int maxi=0;
        while(r<n){
            if(mp.find(s[r]) != mp.end()){
                if(mp[s[r]] >= l){
                    l=mp[s[r]]+1;
                }
            }
            int length=r-l+1;
            maxi=max(maxi,length);
            mp[s[r]]=r;
            r++;
        }
        return maxi;
    }
};
