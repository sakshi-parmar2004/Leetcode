class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = 0, ele2 = 0, count1 = 0, count2 = 0;
        int n = nums.size();

        // First pass: Find candidates
        for (int num : nums) {
            if (ele1 == num) {
                count1++;
            }
            else if (ele2 == num) {
                count2++;
            }
            else if (count1 == 0) {
                ele1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                ele2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Second pass: Verify counts
        count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == ele1) count1++;
            else if (num == ele2) count2++; // `else if` to avoid double-counting when ele1 == ele2
        }

        vector<int> ans;
        if (count1 > n / 3) ans.push_back(ele1);
        if (count2 > n / 3) ans.push_back(ele2);

        return ans;
    }
};
