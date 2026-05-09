class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            while(!st.empty() && asteroids[i]<0 && st.top()>0){
                int sum=asteroids[i]+st.top();
                if(sum<0){
                    st.pop();
                }else if(sum>0){
                    asteroids[i]=0;
                }else{
                    st.pop();
                    asteroids[i]=0;
                }
            }
            if(asteroids[i]!=0){
                st.push(asteroids[i]);
            }
        }
        int s=st.size();
        vector<int> result(s);
        int j=s-1;
        while(!st.empty()){
            result[j]=st.top();
            st.pop();
            j--;
        }
        return result;
    }
};
