class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = findpivot(nums);
        if(pivot == -1){
            // normal binary search
            return binarySearch(nums,0,nums.size()-1,target);
        }
        if(target == nums[pivot]) return pivot;


if(target >= nums[0]){
    return binarySearch(nums,0,pivot,target);
}
else{
    return binarySearch(nums,pivot+1,nums.size()-1,target);
}
    }

    int binarySearch(vector<int>& arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return -1;
    }

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
};
