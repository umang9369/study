class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int curr,vector<int>& color,int newcolor){
        color[curr]=newcolor;
        for(int &v:graph[curr]){
            if(color[v]==color[curr]){
                return false; //same mil gya color ka node
            }
            if(color[v]==-1){
                int colorV=1-newcolor;
                if(dfs(graph,v,color,colorV)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        //red=1 and green =0
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(graph,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
