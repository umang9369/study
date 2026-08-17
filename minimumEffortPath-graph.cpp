class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        res[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff=pq.top().first;
            auto cord=pq.top().second;
            pq.pop();
            int x=cord.first;
            int y=cord.second;
            for(auto & dir:dirs){
                int newx=x+dir[0];
                int newy=y+dir[1];
                if(newx>=0 && newx<m && newy>=0 && newy<n){
                    int absdif=abs(heights[x][y]-heights[newx][newy]);
                    int maxdif=max(diff,absdif);
                    if(res[newx][newy]>maxdif){
                        res[newx][newy]=maxdif;
                        pq.push({maxdif,{newx,newy}});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};
