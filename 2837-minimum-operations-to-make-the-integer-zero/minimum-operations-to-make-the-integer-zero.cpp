class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t=1;
        while(true)
        {
            long long val = num1- 1LL*t*num2;
            if(val<0)return -1;

            int bits = __builtin_popcountll(val);
            if(t>=bits && t<=val)return t;
            t++;

        }
        return -1;
    }
};