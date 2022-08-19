class Solution {
public:
    // children that have both neighbors more than or equal to 
    // in rating are 1, should be treated as start points for 
    // traversal.
    // traverse to neighbor that has strictly higher rating. 
    // If rating has candy that is less than or equal to the point
    //  you are exiting, set candy to point exiting+1. 
    void candyTraverse(vector<int>& ratings, vector<int>& candy, int start) {
        int curr = start+1;
        while (curr < ratings.size() && ratings[curr] > ratings[curr-1] && candy[curr] <= candy[curr-1]) {
            candy[curr] = candy[curr-1]+1;
            curr++;
        }
        curr = start-1;
        while (curr >= 0 && ratings[curr] > ratings[curr+1] && candy[curr] <= candy[curr+1]) {
            candy[curr] = candy[curr+1]+1;
            curr--;
        }
    }
    
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) {
            return 1;
        }
        // O(n)
        vector<int> localMin;
        if (ratings[0] < ratings[1]) {
            localMin.push_back(0);
        }
        for (int i = 1; i < ratings.size()-1; i++) {
            if (ratings[i] < ratings[i+1] && ratings[i] <= ratings[i-1]) {
                localMin.push_back(i);
            }
            else if (ratings[i] < ratings[i-1] && ratings[i] <= ratings[i+1]) {
                localMin.push_back(i);
            }
        }
        if (ratings[ratings.size()-1] < ratings[ratings.size()-2]) {
            localMin.push_back(ratings.size()-1);
        }
        
        vector<int> candy(ratings.size(), 1);
        // O(n), the totality of traversals from local mins on an upward slope will cover the
        // entire array on average one time.
        for (int& i: localMin) {
            candyTraverse(ratings, candy, i);
        }
        // O(n)
        int sum = 0;
        for (int& c: candy) {
            sum += c;
        }
        return sum;
    }
};
