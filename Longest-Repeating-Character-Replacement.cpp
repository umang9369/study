class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int maxfreq=0;
        vector<int> mp(26, 0);
        int n=s.size();
        while(r<n){
            mp[s[r]-'A']++;
            maxfreq=max(maxfreq,mp[s[r]-'A']);
            while((r-l+1)-maxfreq >k){
                mp[s[l]-'A']--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
