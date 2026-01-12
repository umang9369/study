#include <stack>
#include <string>

#include <iostream>
using namespace std;
//function making
class Solution {
public:
    bool isValid(string S) {
        stack<char> s;
        
        for (int i = 0; i < S.length(); i++) {
            char ch = S[i];
            
            if (ch == '(' || ch == '{' || ch == '[') {
                s.push(ch);
            } else {
                if (!s.empty()) {
                    char top = s.top();   // FIXED HERE
                    
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) {
                        s.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return s.empty();
    }
};

int main() {
    Solution sol;
    string s1 = "()[]{}";
    string s2 = "(]";
    cout << "Input: " << s1 << " -> " << (sol.isValid(s1) ? "true" : "false") << endl;
    cout << "Input: " << s2 << " -> " << (sol.isValid(s2) ? "true" : "false") << endl;
    return 0;
}
