class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        // Sort by x descending, if tie by y descending
        sort(points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2) {
            if (p1[0] == p2[0]) return p1[1] > p2[1];
            return p1[0] < p2[0];
        });

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1]; // candidate A
            int max_y = INT_MIN;

            for (int j = i+1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1]; // candidate B

                if (y2 > y1) continue; // must be below or equal

                if (y2 > max_y) {
                    max_y = y2;
                    count++;
                }
            }
        }

        return count;
    }
};
