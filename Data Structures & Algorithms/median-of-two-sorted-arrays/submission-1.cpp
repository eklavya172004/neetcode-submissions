class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 ;
        int j = 0 ; 

        int total = nums1.size() + nums2.size();

        int count = 0;
        int curr = 0;
        int prev = 0;

        while(count <= total/2){
            prev = curr;
            if(i < nums1.size() &&
       (j >= nums2.size() || nums1[i] <= nums2[j])){
                curr = nums1[i];
                i++;
            }else{
                curr = nums2[j];
                j++;
            }
            count++;
        }

        if(total % 2 == 1){
            return curr;
        }

        return (prev+curr) / 2.0;
    }
};
