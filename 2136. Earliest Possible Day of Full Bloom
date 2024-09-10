class Solution {
public:
    static bool customSort(pair<int,int>& a, pair<int,int>& b) {
        if (a.second > b.second) {
            return true;
        } else if (a.second < b.second) {
            return false;
        } else {
            return a.first < b.first;
        }
    }

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> plants = vector<pair<int,int>>();
        int n = plantTime.size();

        // time & memory would be faster if i didn't do this but I'm doing it bc its easier to sort lol.
        for (int i = 0; i < n; i++) {
            plants.push_back(pair<int,int>(plantTime[i], growTime[i]));
        }
        sort(plants.begin(), plants.end(), customSort);
        int numDays = 0;
        int growDays = 0;
        for (int i = 0; i < n; i++) {
            numDays += plants[i].first;
            growDays -= plants[i].first;
            if (growDays < 0) {
                growDays = 0;
            }
            growDays = max(growDays, plants[i].second);
        }
        return numDays + growDays;
    }
};
