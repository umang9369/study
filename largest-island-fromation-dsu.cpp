class disjoint{
public:
    vector<int>parent;
    vector<int>rank;
    vector<int> size;
    disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            //size[i]=1;
        }
    }
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent)return;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
            size[x_parent]+=size[y_parent];
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
            size[y_parent]+=size[x_parent];
        }else if(rank[x_parent]==rank[y_parent]){
            parent[x_parent]=y_parent;
            size[y_parent]+=size[x_parent];
            rank[y_parent]++;
        }
    }
};
class Solution {
public:
    bool isvalid(int newr,int newc ,int n){
        return newr>=0 && newr<n && newc>=0 && newc<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjoint ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int idx=0;idx<4;idx++){
                    int newr=i+dr[idx];
                    int newc=j+dc[idx];
                    if(isvalid(newr,newc,n)&&grid[newr][newc]==1){
                        int nodeno=i*n+j;
                        int adjnode=newr*n+newc;
                        ds.unite(nodeno,adjnode);
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int>comp;
                for(int idx=0;idx<4;idx++){
                    int newr=i+dr[idx];
                    int newc=j+dc[idx];
                    if(isvalid(newr,newc,n)&&grid[newr][newc]==1){
                        if(grid[newr][newc]==1){
                            comp.insert(ds.find(newr*n+newc));
                        }
                    }
                }
                int sizetotal=0;
                for(auto it:comp){
                    sizetotal+=ds.size[it];
                }
                mx=max(mx,sizetotal+1);
            }
        }
        for(int cell=0;cell<n*n;cell++){
            mx=max(mx,ds.size[ds.find(cell)]);
        }
        return mx;
    }
};
