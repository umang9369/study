class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;
        int j=0;
        int n=s.length();
        unordered_map<char,int>mp;
        if(t.length()>n) return "";
        int requiredcount=t.length();
        int minwindowsize = INT_MAX;
        int idx=0;
        for(char &ch : t){
            mp[ch]++;
        }
        while(j<n){
            if(mp[s[j]]>0){
                requiredcount--;
            }
            
            mp[s[j]]--;
            while(requiredcount==0){
                int currwindowsize=j-i+1;
                if(minwindowsize>currwindowsize){
                    minwindowsize=currwindowsize;
                    idx=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    requiredcount++;
                }i++;
            }
            j++;
        }
        return minwindowsize==INT_MAX?"":s.substr(idx,minwindowsize);
    }
};
