class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i,j,m,n;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        i=0;
        j=0;
        m=players.size();
        n=trainers.size();
        while(i<m && j<n){
            if(trainers[j]>=players[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};
