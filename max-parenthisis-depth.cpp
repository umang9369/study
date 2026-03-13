class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int max=INT_MIN;
        for(auto c : s){
            if(c=='('){
                count++;
            }
            if(c==')'){
                count--;
            }
            if(count>max){
                max=count;
            }
        }
        return max;
    }
};
//main
