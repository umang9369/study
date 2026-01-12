class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> mp(26,-1);
        for(int i = 0;i<order.length();i++){
            char ch = order[i];
            mp[ch-'a']= i;
        }
        auto mycompartor = [&mp](char& ch1 , char& ch2){
        return mp[ch1-'a'] < mp[ch2-'a'];
        };
        sort(begin(s),end(s),mycompartor);
        return s;
    }
};
