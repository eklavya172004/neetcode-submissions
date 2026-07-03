class Solution {
public:
    vector<string> letterCombinations(string digits) {
            vector<string> ans;

            if(digits == "") return ans;

            f("",digits,ans);

            return ans;
    }

    void f(string p,string up,vector<string>& ans){
        if(up.empty()){
            ans.push_back(p);
            return;
        }

        char ch = up[0];
        int digit = ch -'0';

        int s = 0;
        int e = 0;

        if(digit == 7){
            s = 3 *(digit-2);
            e = 3*(digit-1);
        }else if(digit == 8){
            s = 3 *(digit-2)+1;
            e = 3*(digit-1);
        }else if(digit == 9){
            s = 3 *(digit-2) + 1;
            e = 3*(digit-1) + 1 ; 
        }else{
             s = 3 *(digit-2);
             e = 3*(digit-1) - 1;
        }


        for(int i = s ; i <= e ; i++){
            char toadd = (char) ( 'a' + i );

            f(p+toadd,up.substr(1),ans);
        }
    }
};
