class Solution {
  public:
    void solve(int i , int current , vector<int>& arr , vector<int>& sums ){
        //basecase
        if(i == arr.size()){
            sums.push_back(current);
            return ;
        }
        //take
        solve( i+1 , current + arr[i] , arr , sums );
        //untake
        solve( i+1 , current , arr , sums );
        return;
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sums;
        solve(0,0,arr,sums);
        sort ( sums.begin() , sums.end() );
        return sums ;
    }
};
//add main and include function accordingly
