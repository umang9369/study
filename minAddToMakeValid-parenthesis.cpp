class Solution {
public:
    int minAddToMakeValid(string s) {
        int i=0;
        int j=0;
        for(auto ch:s){
            if(ch=='('){
                i++;
            }else{
                if(i>0){
                    i--;
                }else{
                    j++;
                }
            }
        }
        return i+j;
    }
};
