class unionset{
    vector<int>parent;
    vector<int>rank;
public:
    unionset(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int x_parent=find(x_parent);
        int y_parent=find(y_parent);
        if(x_parent==y_parent)return ;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else if(rank[x_parent]==rank[y_parent]){
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        unionset ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for (int j=1;j<acc[i].size();j++){
                string email=acc[i][j];
                if(mp.find(email)==mp.end()){
                    mp[email]=i;  
                }else{
                    ds.unite(i,mp[email]);
                }
            }
        }
        vector<vector<string>>merged(n);
        for(auto it:mp){
            string email=it.first;
            int accidx=it.second;
            int par=ds.find(accidx);
            merged[par].push_back(email);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merged[i].empty())continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string>temp;
            temp.push_back(acc[i][0]);
            for(string it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
