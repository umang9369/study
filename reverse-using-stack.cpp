#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string reverse(const string& S) {
        string str = S;
        stack<char> s;
        
        for(int i=0; i<str.length() ;i++){
            char ch = str[i];
            s.push(ch);
        }
        string ans = "";
        
        while( !s.empty()){
            char ch = s.top();
            ans.push_back(ch);
            s.pop();
        }
        return ans ;
    }
};

int main() {
    Solution sol;
    string s = "umangsingh";
    cout << "Original: " << s << endl;
    cout << "Reversed: " << sol.reverse(s) << endl;
    return 0;
}
