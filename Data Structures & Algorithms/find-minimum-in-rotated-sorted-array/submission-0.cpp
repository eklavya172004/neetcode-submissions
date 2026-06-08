class Solution {
public:
    int findpivot(vector<int>& nums){
        int s = 0 ; 
        int e = nums.size() -1;
        int n = nums.size();

        while(s<=e){
            int mid = s + (e-s)/2;

            // case1
            if(mid < e && nums[mid] > nums[mid+1]){
                return mid;
            }
            // case 2 
            if(mid > s && nums[mid] < nums[mid-1]){
                return mid-1;
            }

            // case 3 - s>mid
            if(nums[s] >= nums[mid]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return -1;
    }

    int findMin(vector<int> &nums) {
        int pivot = findpivot(nums);

        if(pivot == -1){
            return nums[0];
        }else{
            return nums[(pivot+1)%nums.size()];
        }
    }
};
