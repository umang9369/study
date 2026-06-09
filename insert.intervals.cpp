class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newintervals) {
        vector<vector<int>> res;
        int n=intervals.size();
        int i=0;
        while(i<n && intervals[i][1]<newintervals[0]){
            res.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=newintervals[1]){
            newintervals[0]=min(newintervals[0],intervals[i][0]);
            newintervals[1]=max(newintervals[1],intervals[i][1]);
            i++;
        }
        res.push_back(newintervals);
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
