class Solution {
public:
    //next smallest left ka code
    vector<int> getnsl(vector<int>& arr ,int n){
        vector<int> result(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                result[i]=-1;
            }else{
                while(!st.empty()&& arr[st.top()]>=arr[i]){
                    st.pop();
                }
                result[i]=st.empty()?-1:st.top();
            }
            st.push(i);
        }
        return result;
    }
    //next smallest right ka code
    vector<int> getnsr(vector<int>& arr ,int n){
        vector<int> result(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=n;
            }else{
                while(!st.empty()&& arr[st.top()]>arr[i]){
                    st.pop();
                }
                result[i]=st.empty()?n:st.top();
            }
            st.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nsl =getnsl(arr,n);
        vector<int> nsr =getnsr(arr,n);
        long long sum=0;
        int m=1e9+7;
        for(int i=0;i<n;i++){
            long long ls=i-nsl[i];
            long long rs=nsr[i]-i;
            long long totalways=ls*rs;
            long long totalsum=arr[i]*totalways;
            sum=(sum+totalsum)%m;
        }
        return sum;
    }
};
