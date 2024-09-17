class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int largestRect = 0;
        queue<vector<int>> *prev = NULL;
        for (vector<char>& row: matrix) {
            queue<vector<int>> *next = new queue<vector<int>>();
            while (prev && !prev->empty()) {
                //Find all rectangles in curr between prev intervals
                vector<int>& r = prev->front();
                //cout << r[0] << " " << r[1] << " " << r[2] << endl;
                int j = r[0];
                int start2;
                bool construct = false;
                while (j <= r[1]) {
                    if (!construct && row[j] == '1') {
                        construct = true;
                        start2 = j;
                    }
                    if (construct && row[j] == '0') {
                        construct = false;
                        next->push({start2, j-1, r[2]+1});
                        largestRect = max((r[2]+1)*(j-start2), largestRect);
                    }
                    j++;
                }
                if (construct) {
                    next->push({start2, r[1], r[2]+1});
                    largestRect = max((r[2]+1)*(r[1]+1-start2), largestRect);
                }
                prev->pop();
            }
            delete prev;
            prev = next;
            //Insert curr
            int i = 0;
            int start;
            bool construct = false;
            while (i < row.size()) {
                if (!construct && row[i] == '1') {
                    construct = true;
                    start = i;
                }
                if (construct && row[i] == '0') {
                    construct = false;
                    prev->push({start, i-1, 1});
                    //cout << start << " " << i-1 << " " << endl;
                    largestRect = max((i-start), largestRect);
                }
                i++;
            }
            if (construct) {
                prev->push({start, (int) row.size()-1, 1});
                //cout << start << " " << (int) row.size()-1 << " " << endl;
                largestRect = max((int)row.size()-start, largestRect);
            }
        }
        return largestRect;
    }
};
