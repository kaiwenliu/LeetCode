class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int, greater<int>> heights;
        unordered_map<int,int> counter;
        vector<vector<int>> startEnd;
        for (vector<int>& a: buildings) {
            startEnd.push_back({a[0],a[2]});
            startEnd.push_back({a[1],-a[2]});
        }
        sort(startEnd.begin(), startEnd.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int i = 0;
        int prevH = -1;
        vector<vector<int>> ans;
        while (i < startEnd.size()) {
            if (startEnd[i][1] > 0) {
                heights.insert(startEnd[i][1]);
                counter[startEnd[i][1]]++;
            }
            else {
                counter[-startEnd[i][1]]--;
                if (counter[-startEnd[i][1]] <= 0) {
                    heights.erase(-startEnd[i][1]);
                }
            }
            int x = startEnd[i][0];
            i++;
            while (i < startEnd.size() && startEnd[i][0] == x) {
                if (startEnd[i][1] > 0) {
                    heights.insert(startEnd[i][1]);
                    counter[startEnd[i][1]]++;
                }
                else {
                    counter[-startEnd[i][1]]--;
                    if (counter[-startEnd[i][1]] <= 0) {
                        heights.erase(-startEnd[i][1]);
                    }
                }
                i++;
            }
            if (prevH != *heights.begin()) {
                prevH = *heights.begin();
                ans.push_back({x,prevH});
            }
        }
        return ans;
    }
};
