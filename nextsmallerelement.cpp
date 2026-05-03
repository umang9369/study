class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        vector<int> mp(arr.size());
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(! st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(!st.empty()) {
                mp[i] = st.top();
            } else {
                mp[i] = -1;
            }
            st.push(arr[i]);
        }
        return mp;
    }
};
