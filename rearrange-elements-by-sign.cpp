class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int pi = 0;
        int ni = 1;
        for(int &num : nums){
            if(num > 0){
                result[pi] = num;
                pi += 2; 
            } else {
                result[ni] = num;
                ni += 2;
            }
        }
        return result;
    }
};
//main function khud likho