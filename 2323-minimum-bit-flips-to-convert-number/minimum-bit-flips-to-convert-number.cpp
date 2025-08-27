class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans= __builtin_popcount(start^goal);
        return ans;
        
    }
};