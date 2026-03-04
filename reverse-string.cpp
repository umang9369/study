class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int l = 0;
        int r = 0;
        int n = s.length();

        // reverse whole string first
        reverse(s.begin(), s.end());

        while(i < n){
            
            while(i < n && s[i] == ' ')
                i++;

            l = r;

            while(i < n && s[i] != ' '){
                s[r++] = s[i++];
            }

            if(l < r){
                reverse(s.begin() + l, s.begin() + r);
                s[r] = ' ';
                r++;
            }

            i++;
        }

        if(r > 0)
            s = s.substr(0, r - 1);
        else
            s = "";

        return s;
    }
};
