class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> bars;
        int n = heights.size();
        int maxA = 0;
        bool used;
        for (int i = 0; i < n; i++) {
            int load;
            bool check = false;
            while (!bars.empty() && bars.top().first > heights[i]) {
                maxA = max((i-bars.top().second) * bars.top().first, maxA);
                load = bars.top().second;
                bars.pop();
                check = true;
            }
            if (check && (bars.empty() || bars.top().first < heights[i])) {
                bars.push(pair<int,int>(heights[i], load));
            }
            if (bars.empty() || bars.top().first < heights[i]) {
                bars.push(pair<int,int>(heights[i], i));
            }
        }
        while (!bars.empty()) {
            maxA = max((n - bars.top().second) * bars.top().first, maxA);
            bars.pop();
        }
        return maxA;
    }
};
