#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
                return 0;

            rev = rev * 10 + digit;
        }
        return rev;
    }
};
int main() {
    Solution rev ;
    cout << rev.reverse(123) << endl;
    cout << rev.reverse(-123) << endl;
    cout << rev.reverse(120) << endl;
    cout << rev.reverse(0) << endl;
    cout << rev.reverse(1534236469) << endl;
    cout << rev.reverse(-2147483648) << endl;
    cout << rev.reverse(2147483647) << endl;
    return 0;
}