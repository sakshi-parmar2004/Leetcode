class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int i = 0, j = 0, count0 = 0 , ans=0 , n=nums.size();
        while (j < n) {
            if (nums[j] == 0) {
                count0++;
            }
            while (count0 > k) {
                if (nums[i] == 0) {
                    count0--;
                }
                i++;
            }
            ans= max(ans,j-i+1);
            j++;
        }
       
        
        return ans;
        
    }
};