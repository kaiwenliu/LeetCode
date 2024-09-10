class Solution {
public:
    // y = ax + b
    // a = (y2-y1)/(x2-x1)
    // y2 = ((y2-y1)/(x2-x1))x2 + b
    // b = y2 - ax2
    // Solution is O(n^2 * logn)
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for (int i = 1; i < points.size(); i++) {
            vector<int>& curr = points[i];
            map<vector<int>, int> lines;
            map<int,int> vertLines;
            for (int j = 0; j < points.size(); j++) {
                if (j == i) {
                    continue;
                }
                vector<int>& endP = points[j];
                if (curr[0] == endP[0]) {
                    vertLines[curr[0]]++;
                    ans = max(ans, vertLines[curr[0]]+1);
                }
                else {
                    // Instead of using double, consider using two variables to represent
                    // a rational number for a. Same thing for b, which could be represented
                    // as curr[1]*(curr[0]-endP[0]) - curr[0]*(curr[1]-endP[1]) in the num
                    // and (curr[0]-endP[0]) in the denom.
                    vector<int> line(3);
                    line[0] = (curr[1]-endP[1]);
                    line[1] = (curr[0]-endP[0]);
                    line[2] = curr[1]*(curr[0]-endP[0]) - curr[0]*(curr[1]-endP[1]);
                    int gcd1 = gcd(line[0], line[1]);
                    int gcd2 = gcd(line[2], line[1]);
                    line[0]/=gcd1;
                    line[1]/=gcd1;
                    line[2]/=gcd2;
                    // cout << curr[0] << " " << curr[1] << " ; ";
                    // cout << line[0] << " " << line[1] << " " << line[2] << endl;
                    lines[line]++;
                    ans = max(ans, lines[line]+1);
                }
            }
        }
        return ans;
    }
};
