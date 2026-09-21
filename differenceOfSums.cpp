class Solution {
public:
    int differenceOfSums(int n, int m) {
        int nums1=0;
        int nums2=0;
        for(int i=1;i<=n;i++){
            if(i%m!=0){
                nums1+=i;
            }else{
                nums2+=i;
            }
        }
        return nums1-nums2;
    }
};
