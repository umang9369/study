class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent) return ;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else if(rank[x_parent]==rank[y_parent]){
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);
        if(connections.size()<n-1)return -1;
        int comp=n;
        for(int i=0;i<n;i++){parent[i]=i;}
        for(auto &vec:connections){
            if(find(vec[0])!=find(vec[1])){
                unite(vec[0],vec[1]);
                comp--;
            }
        }
        return comp-1;
    }
};
