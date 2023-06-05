class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // best transaction that ends/starts at the index
        vector<int> endsBestTrans = vector<int>(prices.size());
        endsBestTrans.at(0) = 0;
        vector<int> startsBestTrans = vector<int>(prices.size());

        int currMin = prices.at(0);
        int currMax = prices.at(0);
        int bestTrans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (currMin > prices.at(i)) {
                currMin = prices.at(i);
                currMax = prices.at(i);
            }
            if (currMax < prices.at(i)) {
                currMax = prices.at(i);
            }
            if (currMax - currMin > bestTrans) {
                bestTrans = currMax - currMin;
            }
            endsBestTrans.at(i) = bestTrans;
        }
        

        int n = prices.size();
        startsBestTrans.at(n-1) = 0;
        
        currMin = prices.at(n-1);
        currMax = prices.at(n-1);
        bestTrans = 0;
        for (int i = n-2; i < prices.size(); i--) {
            if (currMax < prices.at(i)) {
                currMax = prices.at(i);
                currMin = prices.at(i);
            }
            if (currMin > prices.at(i)) {
                currMin = prices.at(i);
            }
            if (currMax - currMin > bestTrans) {
                bestTrans = currMax - currMin;
            }
            startsBestTrans.at(i) = bestTrans;
        }

        int bestResult = 0;
        for (int i = 0; i < n-1; i++) {
            if (startsBestTrans.at(i+1) + endsBestTrans.at(i) > bestResult) {
                bestResult = startsBestTrans.at(i+1) + endsBestTrans.at(i);
            }
            if (endsBestTrans.at(i) > bestResult) {
                bestResult = endsBestTrans.at(i);
            }
        }
        if (endsBestTrans.at(n-1) > bestResult) {
            bestResult = endsBestTrans.at(n-1);
        }
        return bestResult;
    }


};

// Two intervals with greatest positive diff (end higher than start) and are disjoint

// find maximum profit from a single transaction at every point (where the point is the end 
// or further)

// MaxProfit(i) = MaxBetween(MinPrior(i), i) - Prices(MinPrior(i))
// Whenever u encounter a new minimum, set that as the new min price and reset the maximum

// find maximum profit from a single transaction at every point (where point is the start or 
// before)
