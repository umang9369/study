class Solution {
public:
    const int m = 1e9+7;
    int power(long long a,long long  b){
        if( b==0 ){
            return 1;
        }
        long long half = power(a,b/2);
        long long result = (half * half) % m ;

        if (b%2 == 1){
            return result=(result * a ) % m;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long) power (5,(n+1)/2) * power( 4, n/2 )%m;
    }
};

#include <iostream>
int main() {
    Solution sol;
    long long n = 50; // Example input
    std::cout << "Count of good numbers for n = " << n << " is: " << sol.countGoodNumbers(n) << std::endl;
    return 0;
}