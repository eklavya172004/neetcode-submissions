class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        openclose("",n,n,ans);

        return ans;
    }

    void openclose(string p,int o,int c,vector<string>& ans){
        if(o == 0 && c == 0){
            ans.push_back(p);
            return;
        }

        if(o > c){
            return;
        }

        if(o != 0){
            openclose(p+"(",o-1,c,ans);
        }

        if(c != 0){
            openclose(p+")",o,c-1,ans);
        }
    }
};
