class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]==')') count--;
            if(count != 0) ans.push_back(s[i]);
            if(s[i]=='(') count++;
        }
        return ans;
    }
};
//main function
