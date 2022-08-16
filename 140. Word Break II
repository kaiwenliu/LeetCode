class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<vector<int>>> dp(s.length()+1, vector<vector<int>>());
        for (int i = 0; i < s.length(); i++) {
            if (i != 0 && dp[i].empty()) {
                continue;
            }
            for (int j = 0; j < wordDict.size(); j++) {
                if (i + wordDict[j].length() - 1 < s.length() && wordDict[j] == s.substr(i, wordDict[j].length())) {
                    if (i == 0) {
                        dp[wordDict[j].length()].push_back({j});
                    }
                    else {
                        for (vector<int> v: dp[i]) {
                            v.push_back(j);
                            dp[i+wordDict[j].length()].push_back(v);
                        }
                    }
                }
            }
        }
        vector<string> ans;
        for (vector<int> v: dp[s.length()]) {
            string temp = "";
            for (int i = 0; i < v.size()-1; i++) {
                temp += (wordDict[v[i]] + " ");
            }
            temp += wordDict[v[v.size()-1]];
            ans.push_back(temp);
        }
        return ans;
    }
};
