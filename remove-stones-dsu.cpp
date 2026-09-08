class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    void Unite(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if (x_parent==y_parent)return ;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else if(rank[x_parent]==rank[y_parent]){
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Unite(i,j);
                }
            }
        }
        int grps=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                grps++;
            }
        }
        return n-grps;
    }
};
