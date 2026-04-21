class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xoru = start ^ goal;
        int cnt=0;
        while(xoru>0){
            xoru=xoru & (xoru-1);
            cnt++;
        }
        return cnt;
    }
};
