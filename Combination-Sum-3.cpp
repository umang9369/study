class Solution {
public:
    void solve(int k, int n, vector<vector<int>>& ans, vector<int> ans2,int sum , int idx){
        if(sum == n && k == 0){
            ans.push_back(ans2);
            return ;
        }
        if(sum > n){
            return ;
        }
        for(int i = idx ; i <= 9 ; i++){
            if(i > n){
                break ;
            }
            ans2.push_back(i);
            solve( k-1 , n , ans , ans2 , sum+i , i+1 );
            ans2.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans ;
        vector<int> ans2 ;
        solve( k , n , ans , ans2 , 0 , 1 );
        return ans;
    }
};
//write main function 
