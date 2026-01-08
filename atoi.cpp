#include <iostream>
#include <climits>
#include <cctype>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int l = s.length();

        // ignore leading whitespaces
        while (i < l && isspace(s[i])) {
            i++;
        }

        if (i == l) {
            return 0;
        }

        // signedness
        bool negative = false;
        if (s[i] == '-') {
            negative = true;
            i++;
        } 
        else if (s[i] == '+') {
            i++;
        } 
        else if (!isdigit(s[i])) {
            return 0;
        }

        if (i == l) {
            return 0;
        }

        // skip leading zeros
        while (i < l && s[i] == '0') {
            i++;
        }

        int value = 0;

        // extract / conversion
        while (i < l && isdigit(s[i])) {

            int digit = s[i] - '0';

            // overflow check
            if (value > INT_MAX / 10 || 
               (value == INT_MAX / 10 && digit > 7)) {
                return negative ? INT_MIN : INT_MAX;
            }

            value = value * 10 + digit;
            i++;
        }

        if (negative) {
            value = -value;
        }

        return value;
    }   
};

int main() {
    Solution s;
    cout << s.myAtoi("42") << endl;
    cout << s.myAtoi("   -42") << endl;
    cout << s.myAtoi("4193 with words") << endl;
    return 0;
}
