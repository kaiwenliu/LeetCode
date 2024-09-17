class Solution {
public:
    string minWindow(string s, string t) {
        // Prefix Sum? -> keep track of only letters from t -> insert into hash table after
        // subtracting t letters from vector.
        unordered_map<char,int> label;
        map<vector<int>, int> pos;
        int k = 0;
        int c = 0;
        while (c < t.size()) {
            if (label.find(t[c]) == label.end()) {
                label[t[c]] = k;
                k++;
            }
            c++;
        }
        vector<int> val(k, 0);
        for (int i = 0; i < t.size(); i++) {
            val[label[t[i]]]++;
        }
        vector<int> curr(k, 0);
        int start = 0;
        int l = 0;
        int strLen = INT_MAX;
        bool v = false;
        // Sliding window, keep adding new chars when chars of t are not included, and start
        // subtracting unnecessary chars. If unnecessary chars (including duplicates in t) are
        // gone, start adding new chars until all chars of t are included again. Repeat.
        for (int i = 0; i < s.size(); i++) {
            bool valid = true;
            if (label.find(s[i]) != label.end()) {
                curr[label[s[i]]]++;
            }
            for (int j = 0; j < k; j++) {
                if (curr[j] < val[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid && i - l + 1 < strLen) {
                start = l;
                strLen = i-l+1;
                v = true;
                if (label.find(s[l]) != label.end()) {
                    curr[label[s[l]]]--;
                    if (curr[label[s[l]]] < val[label[s[l]]]) {
                        valid = false;
                    }
                }
                l++;
            }
            while (valid && l <= i) {
                // Probably dont need to be checking every time.
                if (i - l + 1 < strLen) {
                    start = l;
                    strLen = i-l+1;
                }
                if (label.find(s[l]) != label.end()) {
                    curr[label[s[l]]]--;
                    if (curr[label[s[l]]] < val[label[s[l]]]) {
                        valid = false;
                    }
                }
                l++;
            }
        }
        if (!v) {
            return "";
        }
        return s.substr(start, strLen);
    }
};
