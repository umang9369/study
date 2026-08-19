class Solution {
public:
    typedef pair<long long,int>P;
    const int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>>adj;
        for(auto &road:roads){
            int u=road[0];
            int v=road[1];
            int time=road[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<long long>res(n,LLONG_MAX);
        vector<int>pathcount(n,0);
        res[0]=0;
        pathcount[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long long currtime=pq.top().first;
            int currnode=pq.top().second;
            pq.pop();
            for(auto &vec:adj[currnode]){
                int adjnode=vec.first;
                int roadtime=vec.second;
                if(currtime+roadtime<res[adjnode]){
                    res[adjnode]=currtime+roadtime;
                    pathcount[adjnode]=pathcount[currnode];
                    pq.push({res[adjnode],adjnode});
                }else if(currtime+roadtime==res[adjnode]){
                    pathcount[adjnode]=(pathcount[adjnode]+pathcount[currnode])%M;
                }
            }
        }
        return pathcount[n-1];
    }
};
