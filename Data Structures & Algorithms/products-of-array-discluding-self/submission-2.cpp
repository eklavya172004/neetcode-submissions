class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    //    method-1
        // // 1 zero case - non zero product 
        // // 2 zero case - everthing becomes zero here
        
        // // case 1
        // int ans = 1;


        // int count_zero = 0;

        // for(int i = 0 ; i < nums.size() ; i++){
        
        // if(nums[i] == 0) count_zero++;

        // if(nums[i] != 0){
        //     ans  *= nums[i];
        // } 
        // }

        // for(int i = 0 ; i < nums.size() ; i++){
        //     if(count_zero > 1){ 
        //         nums[i] = 0; 
        //         continue;
        //         }else if(count_zero == 0){
        //          nums[i] = ans / nums[i];
        //         }else{
        //             if(nums[i] == 0) nums[i] = ans;
        //             else nums[i] = 0;
        //         }
        // }

        // return nums;

        // method - 2
        int n = nums.size();

    vector<int> left(n,1);
    vector<int> right(n,1);

        int i = 1;
        int j = n-2;

        while(i<n && j >= 0){
            left[i] = nums[i-1] * left[i-1];

            right[j] = nums[j+1] * right[j+1];

            i++;
            j--;
        }

        for(int i = 0 ; i < n ; i++){
            nums[i] = left[i] * right[i];
        }

        return nums;
    }
};
