class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;

        vector<string> path;

        pal(s,0,ans,path);

        return ans;
    }

    void pal(string s,int ind,vector<vector<string>>& ans,vector<string>& path){
        if(ind == s.size()){
            ans.push_back(path);
        }

        for(int i = ind ; i < s.size() ; i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));

                pal(s,i+1,ans,path);

                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start] != s[end]){
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};
