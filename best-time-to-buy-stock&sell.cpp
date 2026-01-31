class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int mincount=INT_MAX;
        for(int i=0;i<prices.size();i++){
            mincount=min(mincount,prices[i]);
            maxprofit=max(maxprofit,prices[i]-mincount);
        }
        return maxprofit;
    }
};

//main function khud likho