class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto &v:edges){
            dist[v[0]][v[1]]=v[2];
            dist[v[1]][v[0]]=v[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        int citycnt;
        int ans;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                 if(i!=j && dist[i][j]<= distanceThreshold) cnt++;
            }
            if(cnt<=citycnt){
                ans=i;
                citycnt=cnt;
            }
        }
        return ans;
    }
};
