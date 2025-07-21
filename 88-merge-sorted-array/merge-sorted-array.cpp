class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int gap = (len + 1) / 2;

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                // Case 1: both in nums1
                if (left < m && right < m) {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }
                // Case 2: left in nums1, right in nums2
                else if (left < m && right >= m) {
                    if (nums1[left] > nums2[right - m]) {
                        swap(nums1[left], nums2[right - m]);
                    }
                }
                // Case 3: both in nums2
                else if (left >= m && right >= m) {
                    if (nums2[left - m] > nums2[right - m]) {
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }

                left++;
                right++;
            }

            if (gap == 1) break;
            gap = (gap + 1) / 2;
        }

        // Copy sorted nums2 to nums1's end
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};
