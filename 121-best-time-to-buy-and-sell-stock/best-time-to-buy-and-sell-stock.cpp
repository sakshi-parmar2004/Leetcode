class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

        // leftMin[i] = cheapest price from day 0…i
        vector<int> leftMin(n);
        leftMin[0] = prices[0];
        for (int i = 1; i < n; ++i)
            leftMin[i] = min(leftMin[i - 1], prices[i]);

        // rightMax[i] = highest price from day i…n‑1
        vector<int> rightMax(n);
        rightMax[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; --i)
            rightMax[i] = max(rightMax[i + 1], prices[i]);

        // best profit = max(rightMax[i] - leftMin[i]) for all i
        int best = 0;
        for (int i = 0; i < n; ++i)
            best = max(best, rightMax[i] - leftMin[i]);

        return best;
    }
};
