class Solution {
public:
    int calculate(vector<int>& piles, int k){
        int h = 0 ;

        for(int num : piles){
            h += (num+k-1)/k;
        }

        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = INT_MIN;

        for(int num : piles){
            e = max(e,num);
        }


        while(s<e){
            int mid = s + (e-s) / 2;

            int hours = calculate(piles,mid);

            if(hours <= h){
                e = mid;
            }else{
                s = mid + 1;
            }
        }

        return e;
    }
};
