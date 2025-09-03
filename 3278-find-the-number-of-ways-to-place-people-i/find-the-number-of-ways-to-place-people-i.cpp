class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1]; // A (upper-left)

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int x2 = points[j][0], y2 = points[j][1]; // B (lower-right)

                // Condition: A is upper-left of B
                if (!(x1 <= x2 && y1 >= y2)) continue;

                bool flag = false;
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) continue;

                    int x = points[k][0], y = points[k][1];
                    // Check if point k is inside or on rectangle A-B
                    if (x1 <= x && x <= x2 && y2 <= y && y <= y1) {
                        flag = true;
                        break;
                    }
                }

                if (!flag) count++;
            }
        }

        return count;
    }
};
