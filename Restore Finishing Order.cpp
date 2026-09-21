class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int>st(friends.begin(),friends.end());
        vector<int>res;
        for(int c:order){
            if(st.count(c))res.push_back(c);
        }
        return res;
    }
};
