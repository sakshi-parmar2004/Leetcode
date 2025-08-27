class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while (a > 0 || b > 0 || c > 0) {
            int bit1 = a & 1;   // last bit of a
            int bit2 = b & 1;   // last bit of b
            int data = c & 1;   // last bit of c

            if ((bit1 | bit2) != data) {
                if (data == 1) {
                    count += 1; // need one flip to make OR = 1
                } else {
                    count += bit1 + bit2; // flip both if needed
                }
            }

            // move to next bit
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return count;
    }
};
