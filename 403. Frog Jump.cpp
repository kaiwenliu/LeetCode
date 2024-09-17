class Solution {
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> jump(stones.size(), vector<int>());
        jump[0].push_back(0);
        for (int i = 1; i < stones.size(); i++) {
            for (int j = 0; j < i; j++) {
                int jumpD = stones[i] - stones[j];
                for (int k = 0; k < jump[j].size() && jumpD - jump[j][k] <= 1; k++) {
                    if (abs(jumpD - jump[j][k]) <= 1) {
                        jump[i].push_back(jumpD);
                        break;
                    }
                }
            }
        }
        return !jump[stones.size()-1].empty();
    }
};
