class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool check[26]= {false};
        for(auto c : sentence){
            check[c-'a']=true;
        }
        for(auto c:check){
            if(!c) return false;
        }
        return true;
    }
};