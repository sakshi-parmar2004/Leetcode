class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int k = 0; k < 32; k++) {
            int count = 0;
            for (int i : nums) {
                if ((i >> k) & 1) {
                    count++;
                }
            }
            if (count % 3 != 0) {
                result |= (1 << k); // set k-th bit
            }
        }
        return result;
    }
};
