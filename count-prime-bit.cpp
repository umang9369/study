class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<bool> isprime(n+1,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2; i*i<n;i++){
            if(isprime[i]==true){
                for(int j=2;i*j<n;j++){
                    isprime[i*j]=false;
                }
            }
        }
        int cnt = 0;
        for(int i=2; i< n;i++){
            if(isprime[i]) cnt++;
        }
        return cnt;
    }
};
