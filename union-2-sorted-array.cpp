class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> st;
        vector<int> temp;
        int n1 = a.size();
        int n2 = b.size();
        for(int i=0;i<n1;i++){
            st.insert(a[i]);
        }
        for(int i=0;i<n2;i++){
            st.insert(b[i]);
        }
        for(auto it: st){
            temp.push_back(it);
        }
        return temp;
    }
};
