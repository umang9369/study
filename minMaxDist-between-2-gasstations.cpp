class Solution {
public:
    bool func(vector<int> &stations, double mid, int k) {
        int count = 0;
        for(int i = 1; i < stations.size(); i++) {
            double diff = stations[i] - stations[i - 1];
            count += (int)(ceil(diff / mid)) - 1;
        }
        return count <= k;
    }
    double minMaxDist(vector<int> &stations, int k) {
        double low = 0.0;
        double high = stations.back() - stations.front();
        while(high - low > 1e-6) {
            double mid = low + (high - low) / 2.0;
            if(func(stations, mid, k)) {
                high = mid;   
            } else {
                low = mid;    
            }
        }
        return high;  
    }
};
