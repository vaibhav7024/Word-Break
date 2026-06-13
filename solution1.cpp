class Solution {
public:
    bool solve(int start, string& s, unordered_set<string>& dict,vector<int>& dp){
        if(start==s.size()) return true;
        if(dp[start]!=-1) return dp[start];

        for(int end = start;end<=s.size();end++){
            string sub = s.substr(start,end-start);
            if(dict.count(sub) && solve(end,s,dict,dp))
                return dp[start] = true;
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size()+1,-1);
        return solve(0,s,dict,dp);
    }
};
