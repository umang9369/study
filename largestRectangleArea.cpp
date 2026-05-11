class Solution {
public:
    vector<int> getls(vector<int>& heights,int n){
        vector<int> result(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                result[i]=-1;
            }else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                result[i]=st.empty()?-1:st.top();
            }
            st.push(i);
        }
        return result;
    };
    vector<int> getrs(vector<int>& heights,int n){
        vector<int> result(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=n;
            }else{
                while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            result[i]=st.empty()?n:st.top();
            }
            st.push(i);
        }
        return result;
    };
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxiarea=0;
        vector<int> ls =getls(heights,n);
        vector<int> rs =getrs(heights,n);
        for(int i=0;i<n;i++){
            int area=(rs[i]-ls[i]-1)*heights[i];
            maxiarea=max(maxiarea,area);
        }
        return maxiarea;
    }
};
