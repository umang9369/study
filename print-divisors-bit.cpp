class Solution {
  public:
    void print_divisors(int n) {
        vector<int> arr;
        for(int i=1; i*i<=n;i++){
            if(n%i==0){
                arr.push_back(i);
                if((n/i) != i){
                    arr.push_back(n/i);
                }
            }
        }
        sort(arr.begin(),arr.end());
        for(int x : arr){
            cout << x << " ";
        }
    }
};
