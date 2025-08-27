class Solution {
public:
    int minFlips(int a, int b, int c) {
        // bits where (a|b) != c → need at least 1 flip
        int temp2 = (a | b) ^ c;

        // bits where both a and b are 1, but c is 0 → need +1 extra flip
        int temp3 = (a & b) & temp2;

        // count flips
        int ans = __builtin_popcount(temp2) + __builtin_popcount(temp3);
        return ans;
    }
};
