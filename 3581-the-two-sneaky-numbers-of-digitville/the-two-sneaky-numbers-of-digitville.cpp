class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int xor_total = 0;
        int n = nums.size();
        
        // XOR all elements in nums
        for (int x : nums) xor_total ^= x;

        // XOR all numbers from 0 to n-3 (since two are duplicates)
        for (int i = 0; i < n - 2; i++) xor_total ^= i;

        // Now xor_total = a ^ b (the two sneaky numbers)

        // Find rightmost set bit (position k)
        int k = 0;
        int temp = xor_total;
        while ((temp & 1) == 0) {
            k++;
            temp >>= 1;
        }

        int first = 0, second = 0;

        // Partition nums based on kth bit
        for (int x : nums) {
            if ((x >> k) & 1)
                first ^= x;
            else
                second ^= x;
        }

        // Partition 0..n-3 based on kth bit
        for (int i = 0; i < n - 2; i++) {
            if ((i >> k) & 1)
                first ^= i;
            else
                second ^= i;
        }

        return {first, second};
    }
};
