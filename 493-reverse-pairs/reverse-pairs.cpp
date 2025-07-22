class Solution {
public:
    int merge(vector<int>& arr, int l, int r, int mid) {
        int count = 0;
        int j = mid + 1;

        // Count reverse pairs before merge
        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Now do the standard merge
        int len1 = mid - l + 1;
        int len2 = r - mid;
        vector<int> left(len1), right(len2);
        for (int i = 0; i < len1; ++i) left[i] = arr[l + i];
        for (int i = 0; i < len2; ++i) right[i] = arr[mid + 1 + i];

        int i = 0, k = l;
        j = 0;
        while (i < len1 && j < len2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }
        while (i < len1) arr[k++] = left[i++];
        while (j < len2) arr[k++] = right[j++];

        return count;
    }

    int merge_sort(vector<int>& arr, int l, int r) {
        int count = 0;
        if (l < r) {
            int mid = l + (r - l) / 2;
            count += merge_sort(arr, l, mid);
            count += merge_sort(arr, mid + 1, r);
            count += merge(arr, l, r, mid);
        }
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() - 1);
    }
};
