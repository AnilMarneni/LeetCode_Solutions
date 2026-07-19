class Solution {
public:
    bool solve(int idx, string& s, unordered_set<string>& dict, int dp[300]){
        int n = s.length();
        if(idx == n){
            return dp[idx] = true;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        if(dict.find(s) != dict.end()){
            return dp[idx] = true;
        }

        for(int l = 1; l <= n; l++){
            string temp = s.substr(idx, l);
            bool found = dict.find(temp) != dict.end();
            if(found && solve(idx + l, s, dict, dp)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int dp[300];
        memset(dp, -1, sizeof(dp));
        for(string str : wordDict){
            dict.insert(str);
        }
        return solve(0, s, dict, dp);
    }
};