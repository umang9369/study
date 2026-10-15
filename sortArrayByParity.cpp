class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i]%2==0){
            i++;
        }else if(nums[j]%2==1){
            j--;
        }else{
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
        }
        return nums;
    }
};
