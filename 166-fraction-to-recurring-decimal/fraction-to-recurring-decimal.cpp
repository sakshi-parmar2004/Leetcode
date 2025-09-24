#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;

        // Handle negative numbers
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        // Convert to long long to avoid overflow
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        result += to_string(num / den);
        long long rem = num % den;

        if (rem == 0) return result; // no fractional part

        result += ".";

        // Map remainder -> position in result string
        unordered_map<long long, int> remainderPos;

        while (rem != 0) {
            if (remainderPos.count(rem)) {
                // Insert '(' at the index where this remainder was first seen
                result.insert(remainderPos[rem], "(");
                result += ")";
                break;
            }

            remainderPos[rem] = result.size();
            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
        }

        return result;
    }
};
