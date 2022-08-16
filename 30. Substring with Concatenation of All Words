class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLen = words[0].size();
        int subLen = words.size();
        vector<queue<string>> wordsQ(wordLen, queue<string>());
        vector<unordered_map<string, int>> wordReqs(wordLen, unordered_map<string,int>());
        vector<int> reqsTot(wordLen, words.size());
        for (string s: words) {
            for (unordered_map<string,int>& req: wordReqs) {
                req[s]++;
            }
        }
        vector<int> match;
        // All offsets
        for (int j = 0; j < wordLen; j++) {
            // Get all the first words
            for (int i = j; i < subLen*wordLen + j; i+=wordLen) {
                // If out of bounds, return
                if (i >= s.size()-wordLen+1) {
                    return match;
                }
                // Modify fulfillment of requirements
                string temp = s.substr(i, wordLen);
                if (wordReqs[j].find(temp) != wordReqs[j].end()) {
                    if (wordReqs[j][temp] > 0) {
                        reqsTot[j]--;
                    }
                    else {
                        reqsTot[j]++;
                    }
                    wordReqs[j][temp]--;
                }
                else {
                    reqsTot[j]++;
                }
                // Push to queue
                wordsQ[j].push(temp);
            }
            // If all reqs are fulfilled
            if (reqsTot[j] == 0) {
                match.push_back(j);
            }
        }
        for (int j = wordLen*subLen; j < s.size()-wordLen+1; j++) {
            int off = j%wordLen;
            
            string popped = wordsQ[off].front();
            wordsQ[off].pop();
            if (wordReqs[off].find(popped) != wordReqs[off].end()) {
                if (wordReqs[off][popped] < 0) {
                    reqsTot[off]--;
                }
                else {
                    reqsTot[off]++;
                }
                wordReqs[off][popped]++;
            }
            else {
                reqsTot[off]--;
            }
            
            string temp = s.substr(j, wordLen);
            if (wordReqs[off].find(temp) != wordReqs[off].end()) {
                if (wordReqs[off][temp] > 0) {
                    reqsTot[off]--;
                }
                else {
                    reqsTot[off]++;
                }
                wordReqs[off][temp]--;
            }
            else {
                reqsTot[off]++;
            }
            // Push to queue
            wordsQ[off].push(temp);
            if (reqsTot[off] == 0) {
                match.push_back(j-wordLen*(words.size()-1));
            }
        }
        return match;
        
    }
};
