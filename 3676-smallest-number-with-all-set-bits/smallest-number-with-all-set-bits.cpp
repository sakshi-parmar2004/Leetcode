#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool allOnes(int n) {
        while (n > 0) {
            if (!(n & 1))  // if any bit is 0
                return false;
            n >>= 1;
        }
        return true;
    }

    int smallestNumber(int n) {
        for (int i = n; i <= INT_MAX; i++) {
            if (allOnes(i)) return i;
        }
        return -1;
    }
};
