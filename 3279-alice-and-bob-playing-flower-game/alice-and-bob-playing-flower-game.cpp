class Solution {
public:
    long long flowerGame(int n, int m) {
        long long count = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                int odd_number = 0;
                // how many odd number in range 1-m
                if (m % 2 == 0) {
                    odd_number = m / 2;
                } else {
                    odd_number = (m / 2) + 1;
                }
                count += odd_number;
            } else {
                // how many even umbers in range 1-m

                int even_number = m / 2;

                count += even_number;
            }
        }
        return count;
    }
};