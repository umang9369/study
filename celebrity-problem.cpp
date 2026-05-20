class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        stack<int>st;
        for(int i=0;i<mat.size();i++){
            st.push(i);
        }
        while(st.size()>1){
            int i=st.top();
            st.pop();
            int j=st.top();
            st.pop();
            if(mat[i][j]==0){
                st.push(i);
            }else{
                st.push(j);
            }
        }
        int celeb = st.top();
        for(int i=0;i<mat.size();i++){
            if((i!=celeb) && (mat[i][celeb]==0 || mat[celeb][i]==1)){
                return -1;
            }
        }
        return celeb;
    }
};
