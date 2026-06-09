class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals),comp);
        int count=1;
        int lasttime=intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=lasttime){
                count++;
                lasttime=intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
};
